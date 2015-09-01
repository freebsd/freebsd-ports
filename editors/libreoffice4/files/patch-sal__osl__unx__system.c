--- sal/osl/unx/system.c.orig	2014-09-16 16:10:41.000000000 -0400
+++ sal/osl/unx/system.c	2014-10-14 15:48:58.000000000 -0400
@@ -298,6 +298,9 @@
 #endif /* NO_PTHREAD_RTL */
 
 #if defined(FREEBSD)
+
+#include <math.h>
+
 char *fcvt(double value, int ndigit, int *decpt, int *sign)
 {
   static char ret[256];
