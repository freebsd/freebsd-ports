--- cnv/rletoabA62/rletoabA62.c.orig	1992-04-30 23:15:19.000000000 +0900
+++ cnv/rletoabA62/rletoabA62.c	2012-10-16 00:25:35.000000000 +0900
@@ -42,6 +42,10 @@
 */
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <unistd.h>
+#include <fcntl.h>
 
 #ifndef TRUE
 #define TRUE 1
@@ -101,7 +105,7 @@
  * Main entry...
  */
 
-void
+int
 main(argc,argv)
 int argc;
 char **argv;
