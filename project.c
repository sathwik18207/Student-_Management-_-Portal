#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define CANDIDATE_COUNT 16
#define TIFFIN1 "Dosa"
#define TIFFIN2 "Idli"
#define TIFFIN3 "POHA"
#define TIFFIN4 "Puri"
#define lunch1 "Sambar"
#define lunch2 "dahi brinjal"
#define lunch3 "ragmaa"
#define lunch4 "Mix vegcurry"
#define snacks1 "Pav Bhaji"
#define snacks2 "Vada pav"
#define snacks3 "Pani puri"
#define snacks4 "Millets"
#define dinner1 "chicken,paneer"
#define dinner2 "Chicken,mushroom"
#define dinner3 "fish,paneer"
#define dinner4 "Mutton,kobta curry"
int arr[4][4], brr[4][4], h[4][4];
typedef struct voting
{
    int rolno, rolll;
} voting;
typedef struct student
{
    int rno;
    char name[20];
    char pass[20], iss[500], iss1[500];
    int su1, su2, su3, su4, su5, su6, at1, at2, at3, at4, att;
    float cg;
} student;
void line()
{
    int q;
    for (q = 0; q < 50; q++)
        printf("-");
    printf("\n");
}
void zero()
{
    voting *v;
    int i, j,n=1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            arr[i][j] = 0;
        }
    }
    FILE *fp,*fp1;
    fp = fopen("sub.txt", "w");
    fp1=fopen("votrs.txt","w");
    for(i=0;i<n;i++)
    {
       v[i].rolno = 0;
        fflush(stdin);
        v[i].rolll = 0;
        fwrite(&v[i], sizeof(voting), 1, fp1); 
    }
    
    fwrite(arr, sizeof(int), 16, fp);
    fclose(fp);
    fclose(fp1);
}
void votla(int roll)
{
    voting *v;
    int n = 1, i;
    FILE *fp;
    v = (voting *)calloc(n, sizeof(voting));
    fp = fopen("votrs.txt", "a");
    for (i = 0; i < n; i++)
    {
        v[i].rolno = roll;
        v[i].rolll = roll;
        fwrite(&v[i], sizeof(voting), 1, fp);
    }
    fclose(fp);
}
void menu()
{
    FILE *fp;
int i,j;
fp=fopen("sub.txt","r");
fread(arr,sizeof(int),16,fp);
    int a, b, t;

    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < 4; b++)
        { 
            brr[a][b] = arr[a][b];
        }
 
    }
 
    for (b = 0; b < 4; b++)
    {
        for (a = 0; a < 3; a++)
        {
            if (brr[b][a] > brr[b][a + 1])
            {
                t = brr[b][a + 1];
                brr[b][a + 1] = brr[b][a];
                brr[b][a] = t;
            }
        }
    }
     line();
    printf(RED "Your breakfast for tomorrow is \n");
    if (arr[0][0] == brr[0][3])
    {
        printf("%s %d\n", TIFFIN1, brr[0][3]);
    }
    else if (arr[0][1] == brr[0][3])
    {
        printf("%s %d\n", TIFFIN2, brr[0][3]);
    }
    else if (arr[0][2] == brr[0][3])
    {
        printf("%s %d\n", TIFFIN3, brr[0][3]);
    }
    else if (arr[0][3] == brr[0][3])
    {
        printf("%s %d\n", TIFFIN4
    , brr[0][3]);
    }
    printf(" Your lunch  for tomorrow is \n");
    if (arr[1][0] == brr[1][3])
    {
        printf("%s %d\n", lunch1, brr[1][3]);
    }
    else if (arr[1][1] == brr[1][3])
    {
        printf("%s %d\n", lunch2, brr[1][3]);
    }
    else if (arr[1][2] == brr[1][3])
    {
        printf("%s %d\n", lunch3, brr[1][3]);
    }
    else if (arr[1][3] == brr[1][3])
    {
        printf("%s %d\n", lunch4, brr[1][3]);
    }
    printf(" Your snacks for tomorrow is \n");
    if (arr[2][0] == brr[2][3])
    {
        printf("%s %d\n", snacks1, brr[2][3]);
    }
    else if (arr[2][1] == brr[2][3])
    {
        printf("%s %d\n", snacks2, brr[2][3]);
    }
    else if (arr[2][2] == brr[2][3])
    {
        printf("%s %d\n", snacks3, brr[2][3]);
    }
    else if (arr[2][3] == brr[2][3])
    {
        printf("%s %d\n", snacks4, brr[2][3]);
    }
    printf(" Your dinner is\n");
    if (arr[3][0] == brr[3][3])
    {
        printf("%s %d\n", dinner1, brr[3][3]);
    }
    else if (arr[3][1] == brr[3][3])
    {
        printf("%s %d\n", dinner2, brr[3][3]);
    }
    else if (arr[3][2] == brr[3][3])
    {
        printf("%s %d\n", dinner3, brr[3][3]);
    }
    else if (arr[3][3] == brr[3][3])
    {
        printf("%s %d" RESET"\n", dinner4, brr[3][3]);
    }
    fclose(fp);
}
void votesCount()
{
    FILE *fp;
    fp=fopen("sub.txt","r");
fwrite(arr,sizeof(int),16,fp);
    printf(YELLOW"\n\n ##### Voting Statics ####");
    printf("\n %s - %d ", TIFFIN1, arr[0][0]);
    printf("\n %s - %d ", TIFFIN2, arr[0][1]);
    printf("\n %s - %d ", TIFFIN3, arr[0][2]);
    printf("\n %s - %d "RESET, TIFFIN4
, arr[0][3]);
    printf(GREEN"\n %s - %d ", lunch1, arr[1][0]);
    printf("\n %s - %d ", lunch2, arr[1][1]);
    printf("\n %s - %d ", lunch3, arr[1][2]);
    printf("\n %s - %d "RESET, lunch4, arr[1][3]);
    printf(CYAN"\n %s - %d ", snacks1, arr[2][0]);
    printf("\n %s - %d ", snacks2, arr[2][1]);
    printf("\n %s - %d ", snacks3, arr[2][2]);
    printf("\n %s - %d "RESET, snacks4, arr[2][3]);
    printf(MAGENTA"\n %s - %d ", dinner1, arr[3][0]);
    printf("\n %s - %d ", dinner2, arr[3][1]);
    printf("\n %s - %d ", dinner3, arr[3][2]);
    printf("\n %s - %d "RESET, dinner4, arr[3][3]);
    printf("\n");
    fclose(fp);
}
void castvote(int roll)
{

    int choice1,
        choice2,
        choice3,
        choice4;
    
    printf("\n\n ### Please choose your menu ###\n");

    printf(YELLOW"\n 1. %s", TIFFIN1);

    printf("\n 2. %s", TIFFIN2);

    printf("\n 3. %s", TIFFIN3);

    printf("\n 4. %s"RESET, TIFFIN4
);
    printf(GREEN"\n 5. %s", lunch1);
    printf("\n 6. %s", lunch2);
    printf("\n 7. %s", lunch3);
    printf("\n 8. %s"RESET, lunch4);
    printf(BLUE"\n 9. %s", snacks1);
    printf("\n 10. %s", snacks2);
    printf("\n 11. %s", snacks3);
    printf("\n 12. %s"RESET, snacks4);
    printf(MAGENTA"\n 13. %s", dinner1);
    printf("\n 14. %s", dinner2);
    printf("\n 15. %s", dinner3);
    printf("\n 16. %s\n"RESET, dinner4);
    line();
    printf(CYAN"\n\n Input your choice (1 - 4) : "RESET);
    scanf("%d", &choice1);
    while (choice1 > 4 || choice1 < 1)
    {
        printf(RED"Enter the choice given in the range :"RESET);
        scanf("%d", &choice1);
    }
    printf(MAGENTA"\n\n Input your choice (5 - 8) : "RESET);
    scanf("%d", &choice2);
    while (choice2 > 8 || choice2 < 5)
    {
        printf(RED"Enter the choice given in the range :"RESET);
        scanf("%d", &choice2);
    }
    printf(YELLOW"\n\n Input your choice (9 - 12) : "RESET);
    scanf("%d", &choice3);
    while (choice3 > 12 || choice3 < 8)
    {
        printf(RED"Enter the choice given in the range :"RESET);
        scanf("%d", &choice3);
    }
    printf(GREEN"\n\n Input your choice (13 - 16) : "RESET);
    scanf("%d", &choice4);
    while (choice4 > 16 || choice4 < 13)
    {
        printf(RED"Enter the choice given in the range :"RESET);
        scanf("%d", &choice4);
    }
    
FILE *fp;
fp=fopen("sub.txt","r");
fwrite(arr,sizeof(int),16,fp);
    switch (choice1)
    {
    case 1:
        arr[0][0]++;
        break;
    case 2:
        arr[0][1]++;
        break;
    case 3:
        arr[0][2]++;
        break;
    case 4:
        arr[0][3]++;
        break;

    default:
        printf(RED"\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice2)
    {
    case 5:
        arr[1][0]++;
        break;
    case 6:
        arr[1][1]++;
        break;
    case 7:
        arr[1][2]++;
        break;
    case 8:
        arr[1][3]++;
        break;

    default:
        printf("\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice3)
    {
    case 9:
        arr[2][0]++;
        break;
    case 10:
        arr[2][1]++;
        break;
    case 11:
        arr[2][2]++;
        break;
    case 12:
        arr[2][3]++;
        break;

    default:
        printf("\n Error: Wrong Choice !! Please retry");

        getchar();
    }
    switch (choice4)
    {
    case 13:
        arr[3][0]++;
        break;
    case 14:
        arr[3][1]++;
        break;
    case 15:
        arr[3][2]++;
        break;
    case 16:
        arr[3][3]++;
        break;
fclose(fp);
    default:
        printf("\n Error: Wrong Choice !! Please retry"RESET);

        getchar();
    }

    printf(GREEN"\n thanks for vote !!"RESET);
fp=fopen("sub.txt","w");
fwrite(arr,sizeof(int),16,fp);
fclose(fp);

    votla(roll);
}
void votver(int roll)
{
    voting v1;
    FILE *fp;
    int f = 1;
    fp = fopen("votrs.txt", "r");
    while (fread(&v1, sizeof(voting), 1, fp))
    {
        if (roll == v1.rolll)
        {
            f = 0;
        }
    }
    if (f == 1)
        castvote(roll);
    else
        printf(RED"You have already casted your vote"RESET);
}
int input(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("pqr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(RED"\nNo such student found "RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
int input1(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("pqr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(RED"\nNo such student found "RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
int input2(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, n, j;
    char ps[20];
    fp = fopen("pqr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
        }
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(RED"\nNo such student found "RESET);
        return 0;
    }
    else
    {
        return 1;
    }
}
void changepass(int roll,char na[])
{
{
    student s1;
    FILE *fp, *fp1;
    char name;
    int f = 0;
    fp = fopen("pqr.txt", "r");
    fp1 = fopen("trs.txt", "w");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == roll)
        {
            f = 1;
            fflush(stdin);
            strcpy(s1.name,na);
            printf(CYAN"enter the  new password :");
            scanf("%s", s1.pass);
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("trs.txt", "r");
        fp = fopen("pqr.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(YELLOW"\n record not found ");
}
}
void displaysm(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, a;
    char ps[20];
    fp = fopen("pqrs.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            if((s1.su1<5)||(s1.su2<5)||(s1.su3<5)||(s1.su4<5)||(s1.su5<5)||(s1.su6<5))
            printf(RED"You have failed.Better luck next time\n"RED);
            printf(GREEN"MA1L001:%d\n"RESET CYAN"CS1L001:%d\n"BLUE"ME1L001:%d\n "YELLOW"CY1L001:%d\n"GREEN"CS1P001:%d\n"YELLOW"PH1P001:%d\n "RESET"CG:%f\n", s1.su1, s1.su2, s1.su3, s1.su4, s1.su5, s1.su6, s1.cg);
        }
    }
    if ((f == 0))
    {
        printf(RED"Your marks are not updated"RESET);
    }
    

}
void displaysa(int roll)
{
    int i;
    student s1;
    FILE *fp;
    int f = 0, a;
    char ps[20];
    fp = fopen("pqrr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            printf(BLUE"Your attendance for mess");
            printf(YELLOW"1.Breakfast: %d\n"GREEN"2.Lunch: %d\n"CYAN"3.Snacks: %d\n"MAGENTA"4.Dinner: %d\n"BLUE"5.Refunded amount: %d"RESET, s1.at1, s1.at2, s1.at3, s1.at4, (6600 - s1.att));
            printf("\n");
        }
    }
    if (f == 0)
    {
        printf(RED"No attendance update\n"RESET);
    }
}
void displaysi(int roll)
{
    student s1;
    FILE *fp;
    int o = 1;

    fp = fopen("iss.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            printf(RED"%d. %s\n"RESET, o, s1.iss);
            o++;
        }
    }
}
void displaym()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("pqrs.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(YELLOW"Roll no: %d\n"RESET, s1.rno);
        printf(GREEN"MA1L001:%d\n"YELLOW"CS1L001:%d\n"BLUE"ME1L001:%d\n"GREEN"CY1L001:%d\n"RED"CS1P001:%d\n" MAGENTA "PH1P001:%d\n"CYAN"CG:%f\n"RESET, s1.su1, s1.su2, s1.su3, s1.su4, s1.su5, s1.su6, s1.cg);
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
}
void displaya()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("pqrr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(BLUE"roll no: %d\n"RESET, s1.rno);
        printf(CYAN"Your attendance for mess"RESET);
        printf(MAGENTA"1.Breakfast: %d\n"BLUE"2.Lunch: %d\n"YELLOW"3.Snacks: %d\n"GREEN
        "4.Dinner: %d\n" RED" 5.Refunded amount = %d"GREEN, s1.at1, s1.at2, s1.at3, s1.at4, (6600 - s1.att));
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
}
void displayi()
{
    student s1;
    FILE *fp;
    int j;

    fp = fopen("issu.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf("\n%d    ", s1.rno);
        printf("%s\n", s1.iss);
    }
    fclose(fp);
}
void login1()
{
    int i;
    student s1;
    FILE *fp;
    int roll, a, f = 0;
    char ps[20];
    fp = fopen("pqr.txt", "r");
    printf(GREEN"Enter your id\n");
    scanf("%d", &roll);
    printf("Enter your password\n"RESET);
    char df;
    int vb = 0;
    while ((df = _getch()) != 13)
    {
        ps[vb] = df;
        vb++;
        printf("*");
    }
    printf("\n");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno && (0 == strcmp(s1.pass, ps)))
        {
            f = 1;
            printf(CYAN"\n1.Rollno: %-d\n"MAGENTA"2.Name: %-s\n"BLUE"3.Password: %-s\n"RESET, s1.rno, s1.name, s1.pass);
            do
            {
                printf(MAGENTA"\n1.Display marks");
                printf(BLUE"\n2.Mess fee");
                printf(YELLOW"\n3.Cast vote");
                printf(GREEN"\n4.Issue slips and due date");
                printf(MAGENTA"\n5.Change Password");
                printf(RED"\n0.Exit");
                printf(CYAN"\nEnter your choice\n"RESET);
                scanf("%d", &a);
                if (a == 1)
                    displaysm(roll);
                else if (a == 2)
                    displaysa(roll);
                else if (a == 3)
                    votver(roll);
                    else if(a==4)
                    displaysi(roll);
                    else if(a==5)
                    changepass(roll,s1.name);
            } while (a != 0);
            printf(RED"Logout successfully\n"RESET);
        }
    }
    printf(RED"Wrong entry of roll id or password"RESET);

    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(RED"\nRecord not found\n "RESET);
    }
}
void create()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(GREEN"Number of students :"RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqr.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(MAGENTA"Enter roll no :");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(BLUE"Enter name :");
        scanf("%[^\n]s", s[i].name);
        printf(YELLOW"Enter the password :"RESET);
        scanf("%s", s[i].pass);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void display()
{
    student s1;
    FILE *fp;
    int j;
    fp = fopen("pqr.txt", "r");
    while (fread(&s1, sizeof(student), 1, fp))
    {
        printf(YELLOW"\n1.Rollno: %-d\n"GREEN"2.Name: %-s\n"BLUE"3.Password: %-s"RESET, s1.rno, s1.name, s1.pass);
        printf("\n");
        line();
    }
    printf("\n");
    fclose(fp);
    displaym();
    displaya();
    displayi();
}
void add()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(BLUE"Number of students :"RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqr.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(CYAN"Enter roll no :"RESET);
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(MAGENTA"Enter name :"RESET);
        scanf("%[^\n]s", s[i].name);
        printf(BLUE"Enter the password :"RESET);
        scanf("%s", s[i].pass);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void edit()
{
    student s1;
    FILE *fp, *fp1;

    int f = 0, rno;
    fp = fopen("pqr.txt", "r");
    fp1 = fopen("trs.txt", "w");
    printf(GREEN"Enter the roll no to update :"RESET);
    scanf("%d", &rno);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == rno)
        {
            f = 1;
            fflush(stdin);
            printf(BLUE"Enter  new name :"RESET);
            scanf("%[^\n]s", s1.name);
            printf(YELLOW"Enter the  new password :"RESET);
            scanf("%s", s1.pass);
        }
        fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("trs.txt", "r");
        fp = fopen("pqr.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(RED"\n Record not found "RESET);
}
void delete()
{

    student s1;
    FILE *fp, *fp1;

    int f = 0, rno;
    fp = fopen("pqr.txt", "r");
    fp1 = fopen("temp.txt", "w");
    printf(RED"Enter the roll no to delete :"RESET);
    scanf("%d", &rno);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (s1.rno == rno)
        {
            f = 1;
        }
        else

            fwrite(&s1, sizeof(student), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (f)
    {
        fp1 = fopen("temp.txt", "r");
        fp = fopen("pqr.txt", "w");
        while (fread(&s1, sizeof(student), 1, fp1))
        {
            fwrite(&s1, sizeof(student), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
        printf(RED"\n Record not found "RESET);
}
void search()
{
    int i;
    student s1;
    FILE *fp;
    int roll, f = 0;
    char ps[20];
    fp = fopen("pqr.txt", "r");
    printf("enter your id :\n");
    scanf("%d", &roll);
    while (fread(&s1, sizeof(student), 1, fp))
    {
        if (roll == s1.rno)
        {
            f = 1;
            printf(GREEN"\n1.Rollno: %-d\n"YELLOW"2.Name: %-s\n"BLUE"3.Password: %-s"RESET, s1.rno, s1.name, s1.pass);
            line();
            displaysm(roll);
            printf("\n");
            line();
            displaysa(roll);
        }
        // return f;
    }
    printf("\n");
    fclose(fp);
    if (f == 0)
    {
        printf(RED"\nRecord not found "RESET);
    }
}
void marks()
{

    student *s;
    int n, i, j;
    FILE *fp;
    printf(CYAN"Number of students"RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqrs.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(MAGENTA"Enter roll no :"RESET);
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(RED"Enter subject grades \n"RESET);
        printf(MAGENTA"Enter MA1L001 :"RESET);
        scanf("%d", &s[i].su1);
        printf("\n");
        printf(BLUE"Enter CS1L001 :"RESET);
        scanf("%d", &s[i].su2);
        printf("\n");
        printf(YELLOW"Enter ME1L001 :"RESET);
        scanf("%d", &s[i].su3);
        printf("\n");
        printf(GREEN"Enter CY1L001 :"RESET);
        scanf("%d", &s[i].su4);
        printf("\n");
        printf(RED"Enter CS1P001 :"RESET);
        scanf("%d", &s[i].su5);
        printf("\n");
        printf(CYAN"Enter PH1P001 :"RESET);
        scanf("%d", &s[i].su6);
        printf("\n");
        s[i].cg = ((s[i].su1) * 4 + (s[i].su2) * 4 + (s[i].su3) * 4 + (s[i].su4) * 4 + (s[i].su5) * 2 + (s[i].su6) * 2) / 20.0;
        printf(MAGENTA"CG=%f\n"RESET, s[i].cg);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    

    printf("\n");
    fclose(fp);
}
void addm()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(CYAN"Number of students :"RESET);
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqrs.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(MAGENTA"Enter roll no :"RESET);
        scanf("%d", &s[i]);
        if (input(s[i].rno))
        {
            printf(CYAN"Enter subject grades\n");
            printf("enter MA1L001 :");
            scanf("%d", &s[i].su1);
            printf("\n");
            printf(MAGENTA"Enter CS1L001 :");
            scanf("%d", &s[i].su2);
            printf("\n");
            printf(BLUE"Enter ME1L001 :");
            scanf("%d", &s[i].su3);
            printf("\n");
            printf(YELLOW"Enter CY1L001 :");
            scanf("%d", &s[i].su4);
            printf("\n");
            printf(GREEN"Enter CS1P001 :");
            scanf("%d", &s[i].su5);
            printf("\n");
            printf("Enter PH1P001 :");
            scanf("%d", &s[i].su6);
            printf("\n");
            s[i].cg = ((s[i].su1) * 4 + (s[i].su2) * 4 + (s[i].su3) * 4 + (s[i].su4) * 4 + (s[i].su5) * 2 + (s[i].su6) * 2) / 20.0;
            printf(RED"CG=%f\n"RESET, s[i].cg);

            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    fclose(fp);
}
void attend()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(CYAN"Number of students :");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqrr.txt", "w");
    for (i = 0; i < n; i++)
    {
        printf(BLUE"Enter roll no :"RESET);
        scanf("%d", &s[i]);
        if (input1(s[i].rno))
        {
            fflush(stdin);
            printf(CYAN"Enter the attendance of the student\n");
            printf(MAGENTA"Enter the no.of days present on\n");
            printf(BLUE"1.Breakfast :");
            scanf("%d", &s[i].at1);
            printf("\n");
            printf(YELLOW"2.Lunch :");
            scanf("%d", &s[i].at2);
            printf("\n");
            printf(GREEN"3.Snacks :");
            scanf("%d", &s[i].at3);
            printf("\n");
            printf(RED"4.Dinner :");
            scanf("%d", &s[i].at4);
            printf("\n");
            s[i].att = ((s[i]).at1) * 40 + ((s[i]).at2) * 90 + ((s[i]).at3) * 30 + ((s[i]).at4) * 60;
            printf(CYAN"TOTAL AMOUNT = %d"RESET, s[i].att);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    

    printf("\n");
    fclose(fp);
}
void issue()
{
    student *s;
    FILE *fp;
    int n = 1, roll, i;
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("iss.txt", "w+");
    for (i = 0; i < n; i++)
    {

        printf(MAGENTA"Enter rollno");
        scanf("%d", &s[i]);
        fflush(stdin);
        printf(GREEN"Enter the issue regardings and due date"RESET);
        scanf("%[^\n]s", s[i].iss);
        fwrite(&s[i], sizeof(student), 1, fp);
    }
    fclose(fp);
}
void adda()
{
    student *s;
    int n, i, j;
    FILE *fp;
    printf(BLUE"Number of students :");
    scanf("%d", &n);
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("pqrr.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(GREEN"Enter roll no :"RESET);
        scanf("%d", &s[i]);
        if (input1(s[i].rno))
        {
            printf(RED"Enter the attendance of the student\n");
            printf(YELLOW"Enter the no.of days present on\n");
            printf(MAGENTA"1.Breakfast :");
            scanf("%d", &s[i].at1);
            printf("\n");
            printf(BLUE"2.Lunch :");
            scanf("%d", &s[i].at2);
            printf("\n");
            printf(GREEN"3.Snacks :");
            scanf("%d", &s[i].at3);
            printf("\n");
            printf(RED"4.Dinner :");
            scanf("%d", &s[i].at4);
            printf("\n");
            s[i].att = ((s[i]).at1) * 40 + ((s[i]).at2) * 90 + ((s[i]).at3) * 30 + ((s[i]).at4) * 60;
            printf(CYAN"TOTAL AMOUNT = %d"RESET, s[i].att);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    // return f;

    printf("\n");
    fclose(fp);
}
void addi()
{
    student *s;
    FILE *fp;
    int n = 1, roll, i;
    s = (student *)calloc(n, sizeof(student));
    fp = fopen("iss.txt", "a");
    for (i = 0; i < n; i++)
    {
        printf(MAGENTA"Enter rollno :");
        scanf("%d", &s[i]);
        fflush(stdin);
        if (input2(s[i].rno))
        {
            printf(YELLOW"Enter the issue regardings and due date :\n"RESET);
            scanf("%[^\n]s", s[i].iss);
            fwrite(&s[i], sizeof(student), 1, fp);
        }
    }
    fclose(fp);
}
int main()
{
    int ch, p, f, q;
    do
    {
        line();
        printf(MAGENTA"WELCOME TO STUDENT AND ADMINISTRATOR PORTAL\n");
        line();
        printf(BLUE"\n1.Administartor login");
        printf(YELLOW"\n2.Student login");
        printf(RED"\n0.Exit");
        printf(GREEN"\nEnter your choice :"RESET);
        scanf("%d", &p);
        if (p == 1)
        {
             char id[20];
    printf(GREEN"Enter your id :\n");
    scanf("%s", id);
    printf(YELLOW"Enter your password :\n"RESET);
    char q,ps[20],h[20]="admin1",i[20]="!@#$";
    int w = 0,f=0;
    while ((q = _getch()) != 13)
    {
        ps[w] = q;
        w++;
        printf("*");
    }
    printf("\n");
    
    
        if ((0==strcmp(id,h)) && (0 == strcmp(ps,i)))
        { f=1;
            

            {
                
                do{   printf("\n");
                    line();
                    printf(CYAN"\n1.Create");
                    printf(RED"\n2.Display");
                    printf(GREEN"\n3.Add");
                    printf(CYAN"\n4.Edit");
                    printf(MAGENTA"\n5.Search");
                    printf(BLUE"\n6.Delete");
                    printf(YELLOW"\n7.More");
                    printf(GREEN"\n0.Logout");
                    printf(RED"\nEnter your choice :"RESET);
                    scanf("%d", &ch);
                    if (ch == 1)
                        create();
                    else if (ch == 2)
                        display();
                    else if (ch == 3)
                        add();
                    else if (ch == 4)
                        edit();
                    else if (ch == 5)
                        search();
                    else if (ch == 6)
                        delete ();
                    else if (ch == 7)
                    {
                        do
                        {   
                            printf("\n");
                            line();
				            printf(BLUE"1.Create marks entry\n");
                            printf(BLUE"2.Create mess attendance entry\n");
                            printf(YELLOW"3.Create issue slip entry\n");
                            printf(GREEN"4.Enter of marks of the students\n");
                            printf(BLUE"5.Enter mess attendance\n");
                            printf(GREEN"6.Voting result\n");
                            printf(GREEN"7.Tomorrow menu\n");
                            printf(RED"8.Add issue slip\n");
                            printf(GREEN"9.Start Voting\n");
                            printf(YELLOW"0.Exit\n");
                            printf(GREEN"Enter your choice :\n");
                            scanf("%d", &q);
                            if (q == 1)
                                marks();
                            else if (q == 2)
                                attend();
                            else if (q == 3)
                                issue();
                            else if (q == 4)
                                addm();
                            else if (q == 5)
                                adda();
                            else if (q == 6)
                                votesCount();
                            else if (q == 7)
                                menu();
                            else if (q == 8)
                                addi();
                            else if (q == 9)
                                zero();
                        } while (q != 0);
                    }

                } while (ch != 0);
                printf(GREEN"Logout successfully\n"RESET);
                line();
            }
        }
        if(f==0)
        {
            printf(RED"Wrong entry of user id or password\n"RESET);
        }
        }
        else if (p == 2)
        {
            login1();
        }
    } while (p != 0);

    return 0;
}
