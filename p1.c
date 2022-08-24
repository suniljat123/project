#include<stdio.h>
int main()
{
    int f,a[4][4]={0},i,j,b[16],k=0,temp,cnt,d[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    char c,str[100];
    printf("\nEnter User Name:");
    fgets(str,100,stdin);
    str[strlen(str)-1]=NULL;
    printf("                    RULE OF THIS GAME");
    printf("\n1. You can move only 1 step at a time with the arrow keys.\nMove Up:by Up arrow key\nMove Down: Down arrow key\nMove Left: Left arrow key\nMove Right: Right arrow key\n2. You can move numbers at an empty position only.\n3. For each valid move : your total number of moves will decrease by 1.\n4.Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n");
    printf("\n\n              Winning situation:\n");
    printf("------------------------------\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(d[i][j]!=0)
            {
                if(j==3)
                    printf("| %2d |\t",d[i][j]);
                else
                    printf("| %2d\t",d[i][j]);
            }
            else
                printf("|    |\t",d[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e'\nSo Try to win in minimum number of Moves");
    printf("\n\n       Happy Gaming:Good luck");
    printf("\n\nPress any key to start....");
    getch();
    printf("\n\n");
    while(1)
    {
        cnt=401;
        srand(time(0));
        for(i=0;i<15;i++)
        {
            temp=rand()%15+1;
            for(j=0;j<i;j++)
            {
                if(temp==b[j])
                {
                    break;
                }
            }
             if(j==i)
             {
                b[i]=temp;
             }
             else
                i--;
        }
       for(i=0;i<4;i++)
       {
           for(j=0;j<4;j++)
           {
               a[i][j]=b[k];
               k++;
           }
       }
       system("cls");
        printf("Hello %s , Move Remaining : %d\n\n",str,cnt-1);
        printf("------------------------------\n");
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(a[i][j]!=0)
                {
                    if(j==3)
                        printf("| %2d |\t",a[i][j]);
                    else
                        printf("| %2d\t",a[i][j]);
                }
                else
                {
                    if(j==3)
                        printf("|    |\t");
                    else
                        printf("|  \t");
                }
            }
            printf("\n");
        }
        printf("------------------------------\n");
        while(cnt)
        {
            f=0;
            c=getch();
            switch(c)
            {
                case 75://left arrow
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(a[i][j]==0)
                            {
                                if(j<3)
                                {
                                    a[i][j]=a[i][j+1];
                                    a[i][j+1]=0;
                                    break;
                                }
                                else
                                {
                                    a[i][j]=0;
                                    cnt++;
                                }


                            }
                        }
                    }
                    cnt--;
                    break;
                case 77://right arrow
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(a[i][j]==0)
                            {
                                if(j>0)
                                {
                                    a[i][j]=a[i][j-1];
                                    a[i][j-1]=0;
                                    break;
                                }
                                else
                                {
                                    a[i][j]=0;
                                    cnt++;
                                }
                            }
                        }
                    }
                    cnt--;
                    break;
                case 80://down arrow
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(a[i][j]==0)
                            {
                                if(i>0)
                                {
                                    a[i][j]=a[i-1][j];
                                    a[i-1][j]=0;
                                    break;
                                }
                                else
                                {
                                    a[i][j]=0;
                                    cnt++;
                                }
                            }
                        }

                    }
                    cnt--;
                    break;
                case 72://up arrow
                    for(i=0;i<4;i++)
                    {
                        for(j=0;j<4;j++)
                        {

                            if(a[i][j]==0)
                            {
                                f=1;
                                if(i<3)
                                {
                                    a[i][j]=a[i+1][j];
                                    a[i+1][j]=0;

                                }
                                else
                                {
                                    a[i][j]=0;
                                    cnt++;
                                }
                            }
                        }
                        if (f==1)
                            break;
                    }
                    cnt--;

                    break;
                case 101://"e"
                    exit(0);
                case 69://"E"
                    exit(0);
            }//end of switch
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(a[i][j]!=d[i][j]);
                    {
                        f=1;
                        break;
                    }
                }
            }
            system("cls");
            if(f==0)
            {
                printf("Congratulation %s:You Won",str);
                printf("\n\n\n");
                printf("---------------------------------\n");
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(a[i][j]!=0)
                        {
                            if(j==3)
                                printf("| %2d |\t",a[i][j]);
                            else
                                printf("| %2d\t",a[i][j]);
                        }
                        else
                        {
                            if(j==3)
                                printf("|   |\t");
                            else
                                printf("|   |\t");
                        }
                    }
                    printf("\n");
                }
                printf("---------------------------------\n");
                break;
            }
            printf("Hello %s , Move Remaining : %d\n\n",str,cnt-1);
            printf("------------------------------\n");
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(a[i][j]!=0)
                    {
                        if(j==3)
                            printf("| %2d |\t",a[i][j]);
                        else
                            printf("| %2d\t",a[i][j]);
                    }
                    else
                    {
                        if(j==3)
                            printf("|    |\t");
                        else
                            printf("| \t");
                    }
                }
                printf("\n");
            }
            printf("------------------------------\n");
        }//end of while
        if(cnt==0)
        {
            printf("You lost the Match");

        }
        int ch;
        printf("\n\nPress any key to play again:\nPress 2 to Exit:");
        scanf("%d",&ch);
        if(ch==2)
            exit(0);

    }//end of main while
    return 0;
}
