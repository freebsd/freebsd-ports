--- ./kchart/kdchart/KDChartData.h.orig	Mon Dec 10 18:01:12 2001
+++ ./kchart/kdchart/KDChartData.h	Sat May 25 13:27:21 2002
@@ -12,12 +12,8 @@
 
 #include <qstring.h>
 #include <qdatetime.h>
-#ifdef unix
-#include <values.h>
-#else
 #include <float.h>
 #define MINDOUBLE DBL_MIN
-#endif
 
 // Please leave all methods in this class inline!
 // It's necessary since it's part of the interface provided by KDChart
