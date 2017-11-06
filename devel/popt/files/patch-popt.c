--- popt.c.orig	2010-01-19 00:39:10 UTC
+++ popt.c
@@ -22,6 +22,9 @@ extern long long int strtoll(const char *nptr, /*@null
 #include <float.h>
 #endif
 #include <math.h>
+#ifdef __FreeBSD__
+#include <machine/float.h>
+#endif
 
 #include "poptint.h"
 
