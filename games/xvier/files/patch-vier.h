--- ./vier.h.orig	1992-07-29 02:04:23.000000000 +0200
+++ ./vier.h	2014-03-30 13:14:36.798575126 +0200
@@ -1,4 +1,4 @@
-char *malloc();
+#include <stdlib.h>     /* malloc, free, rand */
 
 extern int rows, columns, vnum;
 extern int row_col, row_1_col, row_2_col;
