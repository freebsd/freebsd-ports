--- search.c.orig	1989-03-30 18:04:12 UTC
+++ search.c
@@ -217,7 +217,7 @@ unsigned char hdigit[16], temp[128];
          }
       }
       for(x= 0; x < len - 1; x+= 2){
-         strcpy(hdigit, hex + (len - x - 2), 2);
+         strncpy(hdigit, hex + (len - x - 2), 2);
          hdigit[2]= '\0';
    
          if(hdigit[0] < 96) hdigit[0]= hdigit[0] - 48;
