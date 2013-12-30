--- ./galaxis.c.orig	2010-10-13 12:13:31.000000000 +0200
+++ ./galaxis.c	2013-12-22 12:01:31.000000000 +0100
@@ -15,6 +15,8 @@
 #include <assert.h>
 #include <string.h>
 #include <stdlib.h>
+#include <time.h>
+#include <unistd.h>
 
 #ifndef A_UNDERLINE	/* BSD curses */
 #define	beep()	write(1,"\007",1);
@@ -644,7 +646,7 @@
     }
 }
 
-main(argc, argv)
+int main(argc, argv)
 int argc;
 char *argv[];
 {
