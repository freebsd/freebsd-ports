--- date.y.orig	2008-02-16 02:00:00.000000000 +0100
+++ date.y	2010-06-08 20:20:19.000000000 +0200
@@ -14,6 +14,7 @@
 /* SUPPRESS 287 on yaccpar_sccsid *//* Unused static variable */
 /* SUPPRESS 288 on yyerrlab *//* Label unused */
 
+#include <time.h>
 #include <sys/timeb.h>
 
 #include <ctype.h>
