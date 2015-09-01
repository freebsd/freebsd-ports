--- sal/osl/unx/system.cxx.orig	2015-08-22 06:41:35 UTC
+++ sal/osl/unx/system.cxx
@@ -247,6 +247,9 @@ int macxp_resolveAlias(char *path, int b
 #endif /* NO_PTHREAD_RTL */
 
 #if defined(FREEBSD)
+
+#include <cmath>
+
 char *fcvt(double value, int ndigit, int *decpt, int *sign)
 {
   static char ret[256];
