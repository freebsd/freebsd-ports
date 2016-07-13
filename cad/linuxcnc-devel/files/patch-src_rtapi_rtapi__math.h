--- src/rtapi/rtapi_math.h.orig	2016-06-25 02:19:12 UTC
+++ src/rtapi/rtapi_math.h
@@ -79,7 +79,10 @@ extern __inline double fmin(double __y, 
 #endif
 
 #else
+#pragma push_macro("value")
+#undef value
 #include <math.h>
+#pragma pop_macro("value")
 #endif
 
 #include "rtapi_byteorder.h"
