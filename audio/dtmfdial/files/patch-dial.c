--- dial.c.orig	1998-03-20 16:13:44 UTC
+++ dial.c
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
 
@@ -130,7 +130,7 @@ getvalue(int *arg, int *index, int argc,
 	++*index;
 }
 
-void
+int
 main(int argc, char **argv)
 {
 	char *cp;
