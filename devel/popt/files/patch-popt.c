--- popt.c.orig	2010-01-19 08:39:10.000000000 +0800
+++ popt.c	2010-06-16 00:38:47.000000000 +0800
@@ -22,6 +22,9 @@
 #include <float.h>
 #endif
 #include <math.h>
+#ifdef __FreeBSD__
+#include <machine/float.h>
+#endif
 
 #include "poptint.h"
 
