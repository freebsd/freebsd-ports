--- cftc.c.orig	Sat Jan 29 21:04:00 2005
+++ cftc.c	Sat Jan 29 21:06:09 2005
@@ -4,6 +4,7 @@
 #include "confpile.h"
 
 
+int
 main(int argc,char *argv[]){
   int iError;
   tConfigTree MyCONF;
@@ -28,4 +29,5 @@
     fprintf(stderr,"The error code is %d\n",iError);
     exit(iError);
     }
+  return 0;
   }
