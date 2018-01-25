--- xjdxgen.c.orig	1998-09-11 03:04:21 UTC
+++ xjdxgen.c
@@ -23,7 +23,7 @@
 #include <sys/stat.h>
 
 #include <stdio.h>
-/*#include <stdlib.h>*/
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include "xjdic.h"
@@ -154,7 +154,7 @@ unsigned char **argv;
   db[diclen] = 10;
   db[0] = 10;
   printf("Dictionary size: %ld bytes.\n",dbyte);
-  indlen = (diclen * 3)/4;
+  indlen = (diclen * 3*(sizeof(long)/4))/4;
   jindex = (unsigned long *)malloc(indlen);
   if(jindex == NULL)
   {
@@ -273,6 +273,7 @@ unsigned char **argv;
   jindex[0] = diclen+jiver;
   fwrite(jindex,sizeof(long),indptr+1,fp);
   fclose(fp);
+  return (0);
 }
 /*======function to sort jindex table====================*/
 void jqsort(long lhs, long rhs)
