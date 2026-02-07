--- unixunpk.c.orig	Mon Jul 21 23:51:55 2003
+++ unixunpk.c	Sun Mar 26 23:36:54 2006
@@ -23,17 +23,18 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include "version.h"
 #include "part.h"
 
-extern int optind;
-extern char *optarg;
-
 extern int overwrite_files;
 extern int didchat;
 int quiet;
 
 void usage(void);
+int handleMessage(struct part *inpart, char *defaultContentType,
+		  int inAppleDouble, int extractText);
 
 int main(int argc, char **argv)
 {
@@ -100,7 +101,7 @@
 
 void usage(void) {
     fprintf(stderr, "munpack version %s\n", MPACK_VERSION);
-    fprintf(stderr, "usage: munpack [-f] [-q] [-C directory] [files...]\n");
+    fprintf(stderr, "usage: munpack [-f] [-q] [-t] [-C directory] [files...]\n");
     exit(1);
 }
 
