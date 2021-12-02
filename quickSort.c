#include <stdio.h>

int data[]={12,22,3,41,5,6,17,8,59,18,811};

void printD(void){
    for(int h=0; h<11; h++){
        printf("%d ", data[h]);
    }
    printf("\n");
}

void quick(int left, int right) {
    int pl = left;
    int pr = right;
    
    int pivot = data[(pl+pr)/2];
    
    while(pl<=pr){
        
        while(data[pl]<pivot) pl++;
        while(data[pr]>pivot) pr--;
        if(pl>pr)break;
        if(pl<=pr) { // pl, pr 값이 업데이트 되고 나서 확인
           // printf("%d %d:",pl, pr);
            int temp = data[pl];
            data[pl] = data[pr];
            data[pr] = temp;
            
            pl++;
            pr--;
            
        }
        
    }
    
    if(left < pr) quick(left, pr);
    if(pl<right) quick(pl,right);
    
    
    /*
    while(pl<=pr){
        
        while(data[pl]<pivot) pl++;
        while(data[pr]>pivot) pr--;
        
        if(pl<=pr) { // pl, pr 값이 업데이트 되고 나서 확인
            int temp = data[pl];
            data[pl] = data[pr];
            data[pr] = temp;
            
            pl++;
            pr--;
            
        }
        
    }
     */
    
}

int main() {
    quick(0, 10);
    printD();
}
