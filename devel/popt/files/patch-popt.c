--- popt.c.old	2009-05-07 15:44:42.000000000 -0500
+++ popt.c	2009-05-07 15:47:12.000000000 -0500
@@ -22,6 +22,9 @@
 #include <float.h>
 #endif
 #include <math.h>
+#ifdef __FreeBSD__
+#include <machine/float.h>
+#endif
 
 #include "poptint.h"
 
