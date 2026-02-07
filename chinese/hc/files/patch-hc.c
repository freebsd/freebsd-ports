--- hc.c.orig	2011-09-05 14:33:19.000000000 +0800
+++ hc.c	2011-09-05 14:34:11.000000000 +0800
@@ -54,9 +54,11 @@
 
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
 #include "hclib.h"
 
-static usage(prog)
+static int usage(prog)
 char *prog;
 {
     fprintf(stderr,"usage: %s -m mode -map mapping [-t t1 t2 ...] < file\n", 
@@ -68,6 +70,7 @@ char *prog;
 }
 
 
+int
 main(argc, argv)
 int argc;
 char *argv[];
