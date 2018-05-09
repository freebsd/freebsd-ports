--- modules/core/include/opencv2/core/types_c.h.orig	2018-02-23 08:38:33 UTC
+++ modules/core/include/opencv2/core/types_c.h
@@ -63,6 +63,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <float.h>
+#include <math.h>
 #endif // SKIP_INCLUDES
 
 #if defined _WIN32
@@ -196,6 +197,38 @@ enum {
 
 #define cvInvSqrt(value) ((float)(1./sqrt(value)))
 #define cvSqrt(value)  ((float)sqrt(value))
+
+#ifndef __cplusplus
+CV_INLINE int cvRound(float value)
+{
+#if ((defined _MSC_VER && defined _M_X64) || ((defined __GNUC__ || defined __clang__) && defined __x86_64__ && \
+      defined __SSE2__ && !defined __APPLE__)) && !defined(__CUDACC__)
+    __m128 t = _mm_set_ss( value );
+    return _mm_cvtss_si32(t);
+#elif defined _MSC_VER && defined _M_IX86
+    int t;
+    __asm
+    {
+        fld value;
+        fistp t;
+    }
+    return t;
+#elif ((defined _MSC_VER && defined _M_ARM) || defined CV_ICC || \
+        defined __GNUC__ || defined __clang__) && defined HAVE_TEGRA_OPTIMIZATION
+    TEGRA_ROUND_FLT(value);
+#elif defined CV_ICC || defined __GNUC__ || defined __clang__
+# if CV_VFP
+    ARM_ROUND_FLT(value);
+# else
+    return (int)lrintf(value);
+# endif
+#else
+    /* it's ok if round does not comply with IEEE754 standard;
+     the tests should allow +/-1 difference when the tested functions use round */
+    return (int)(value + (value >= 0 ? 0.5f : -0.5f));
+#endif
+}
+#endif
 
 
 /*************** Random number generation *******************/
