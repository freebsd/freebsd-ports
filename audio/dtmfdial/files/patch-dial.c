--- dial.c.orig	Fri Mar 31 04:44:07 2006
+++ dial.c	Fri Mar 31 04:44:23 2006
@@ -7,10 +7,10 @@
 #include <math.h>
 #include <stdio.h>
 #include <fcntl.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <sys/types.h>
 #include <sys/stat.h>
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #define DEBUG(x)
 
@@ -130,7 +130,7 @@
 	++*index;
 }
 
-void
+int
 main(int argc, char **argv)
 {
 	char *cp;
