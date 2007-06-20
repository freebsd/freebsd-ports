--- gtex.c.orig	Thu Jul 18 02:22:03 1991
+++ gtex.c	Sat Jun 16 01:11:02 2007
@@ -4,10 +4,12 @@
 #include <stdio.h>
 #include <ctype.h>
 #include <math.h>
+#include <stdlib.h>
+#include <string.h>
 double atan();	/* not in some math.h */
 #include "defs.h"
 #define version_str "4.23"
-char *allocate_mem(), *realloc();
+char *allocate_mem();
 
 /* GPLOT style globals */
 static struct info_struct dev_info;
