--- ./kchart/kdchart/KDChartTable.h.orig	Mon Dec 10 06:53:35 2001
+++ ./kchart/kdchart/KDChartTable.h	Sat May 25 13:28:46 2002
@@ -28,9 +28,9 @@
 #define MAXDOUBLE DBL_MAX
 #define MINDOUBLE DBL_MIN
 #else
-#include <values.h>
-#include <limits.h>
-#include <math.h>
+#include <float.h>
+#define MAXDOUBLE DBL_MAX
+#define MINDOUBLE DBL_MIN
 #endif
 
 #if defined SUN7 || ( defined HP11_aCC && defined HP1100 )
