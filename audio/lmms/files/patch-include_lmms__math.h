--- include/lmms_math.h.orig	2016-05-05 22:56:00 UTC
+++ include/lmms_math.h
@@ -26,15 +26,14 @@
 #ifndef LMMS_MATH_H
 #define LMMS_MATH_H
 
+#include <math.h>
 #include <stdint.h>
 #include "lmms_constants.h"
 #include "lmmsconfig.h"
 #include <QtCore/QtGlobal>
 
-#include <cmath>
 using namespace std;
 
-#if defined (LMMS_BUILD_WIN32) || defined (LMMS_BUILD_APPLE) 
 #ifndef isnanf
 #define isnanf(x)	isnan(x)
 #endif
@@ -53,7 +52,6 @@ using namespace std;
 #ifndef exp10f
 #define exp10f(x) powf( 10, x )
 #endif
-#endif
 
 #ifdef __INTEL_COMPILER
 
