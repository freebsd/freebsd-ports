$FreeBSD$

--- ./kchart/kdchart/KDChartTable.h.orig	Tue Aug 13 18:05:16 2002
+++ ./kchart/kdchart/KDChartTable.h	Tue Aug 13 18:07:10 2002
@@ -23,12 +23,10 @@
 #define MAXDOUBLE DBL_MAX
 #define MINDOUBLE DBL_MIN
 #define std
-#elif defined __APPLE__
+#else
 #include <float.h>
 #define MAXDOUBLE DBL_MAX
 #define MINDOUBLE DBL_MIN
-#else
-#include <values.h>
 #include <limits.h>
 #include <math.h>
 #endif
