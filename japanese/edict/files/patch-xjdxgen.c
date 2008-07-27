--- xjdxgen.c.orig	1998-09-11 05:04:21.000000000 +0200
+++ xjdxgen.c	2008-07-27 20:39:29.000000000 +0200
@@ -23,7 +23,7 @@
 #include <sys/stat.h>
 
 #include <stdio.h>
-/*#include <stdlib.h>*/
+#include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #include "xjdic.h"
@@ -154,7 +154,7 @@
   db[diclen] = 10;
   db[0] = 10;
   printf("Dictionary size: %ld bytes.\n",dbyte);
-  indlen = (diclen * 3)/4;
+  indlen = (diclen * 3*(sizeof(long)/4))/4;
   jindex = (unsigned long *)malloc(indlen);
   if(jindex == NULL)
   {
