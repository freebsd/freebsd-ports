--- xjdserver.c.orig	2024-09-30 19:42:21.985134000 +0100
+++ xjdserver.c	2024-09-30 19:42:39.088405000 +0100
@@ -20,6 +20,7 @@
 
 #include <stdio.h>
 #include <ctype.h>
+#include <errno.h>
 #include <string.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -55,8 +56,6 @@
 int jiver = 14; 
 int thisdic = 0;
 int DicNum;
-
-extern int errno;
 
 extern unsigned char Dnamet[10][100],XJDXnamet[10][100];
 extern unsigned char *dicbufft[10];
