#include <stdio.h>
#include<stdlib.h>
void traverse(int [],int);
void insert(int [],int*);
void deletion(int [],int*);
void search(int [],int n);
void sort(int [],int n);
int main()
{
    int n,ch1;
    int a[100];
    char ch,ch2;
    printf("\nEnter the value of n:");
    scanf("%d",&n);
    printf("\nEnter array of n elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    start:
    do{
        printf("\n1.Insertion");
        printf("\n2.Deletion");
        printf("\n3.traversal");
        printf("\n4.searching");
        printf("\n5.sorting");
        printf("\nEnter value:");
        scanf("%d",&ch1);
    }while(ch1==0);
    
    
    switch(ch1){
        case 1:
            insert(a,&n);
            break;
        case 2:
            deletion(a,&n);
            break;
        case 3:
            traverse(a,n);
            break;
        case 4:
            search(a,n);
            break;
        case 5:
            sort(a,n);
            break;
        default:
            printf("\nInvalid Input!");
            printf("\nDo you like to continue(y/n):");
            scanf("%s",&ch2);
            if(ch2=='y')
                goto start;
    }
   
    return 0;
    
}

void traverse(int a[],int n)
{
    printf("\n\n******************Displaying Array Element******************\n\n");
    for(int i=0;i<n;i++)
    {
        printf("\t %d",a[i]); 
    }
}

void insert(int a[],int* n)
{
    int ele,pos;
    printf("\nEnter element and position to be insert:");
    scanf("%d %d",&ele,&pos);
    for(int i=(*n)-1;i>=pos;i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=ele;
    *n=*n + 1;
     traverse(a,*n);
}

void deletion(int a[],int* n)
{
    int p;
    printf("\nEnter the position to be deleted:");
    scanf("%d",&p);
    for(int i=p;i<(*n);i++)
    {
        a[i]=a[i+1];
    }
    *n=*n - 1;
     traverse(a,*n);
}

void search(int a[],int n)
{
  int e,found;
  printf("\nEnter element: ");
  scanf("%d",&e);
  found=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==e)
    {
        found=1;
        break;
    }
  }
  if(found==1)
        printf("\nElement Found! at index : %d",i);
  else
        printf("\nElement Not Found!");
  
}

void sort(int a[],int n)
{
    int t;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                t=a[i];
                a[j]=a[i];
                a[j]=t;
            }
        }
    }
    traverse(a,n);
}
