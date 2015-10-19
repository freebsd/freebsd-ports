--- sanei/sanei_ir.c.orig	2015-09-29 01:10:43 UTC
+++ sanei/sanei_ir.c
@@ -29,7 +29,8 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <values.h>
+#include <float.h>
+#include <limits.h>
 #include <math.h>
 
 #define BACKEND_NAME sanei_ir	/* name of this module for debugging */
