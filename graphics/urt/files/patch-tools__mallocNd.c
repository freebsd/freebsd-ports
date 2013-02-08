--- tools/mallocNd.c.orig	1992-04-30 23:10:24.000000000 +0900
+++ tools/mallocNd.c	2012-10-16 00:32:49.000000000 +0900
@@ -67,7 +67,7 @@
 
 /* Imports */
 #include <stdio.h>
-extern char *malloc();
+#include <stdlib.h>
 
 /* Forward declarations */
 char *BuildIndirectionTable();
