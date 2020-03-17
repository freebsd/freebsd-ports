--- rxin.c.orig	2020-03-17 01:07:28 UTC
+++ rxin.c
@@ -1399,7 +1399,7 @@ wait:;    
             while(j > 0)
               {
               j--;
-              rxin_int[j]=0x7fffffff*z[j];
+              rxin_int[j]=(float)0x7fffffff*z[j];
               } 
             }
           if(i != (int)snd[RXAD].block_bytes)
