--- common/mathlib.h.orig	2016-03-30 06:24:01 UTC
+++ common/mathlib.h
@@ -12,20 +12,13 @@
 #endif
 
 #ifdef STDC_HEADERS
+#include <sys/limits.h>
 #include <math.h>
 #include <float.h>
 #endif
 
 #include <algorithm>
 
-#if !defined(max) 
-#define max(a,b)            (((a) > (b)) ? (a) : (b))
-#endif
-
-#if !defined(min)
-#define min(a,b)            (((a) < (b)) ? (a) : (b))
-#endif
-
 #define	Q_PI	3.14159265358979323846
 
 extern const vec3_t vec3_origin;
@@ -71,8 +64,8 @@ extern const vec3_t vec3_origin;
 #define VectorCopy(a,b) { (b)[0]=(a)[0]; (b)[1]=(a)[1]; (b)[2]=(a)[2]; }
 #define VectorClear(a)  { (a)[0] = (a)[1] = (a)[2] = 0.0; }
 
-#define VectorMaximum(a) ( max( (a)[0], max( (a)[1], (a)[2] ) ) )
-#define VectorMinimum(a) ( min( (a)[0], min( (a)[1], (a)[2] ) ) )
+#define VectorMaximum(a) ( std::max( (a)[0], std::max( (a)[1], (a)[2] ) ) )
+#define VectorMinimum(a) ( std::min( (a)[0], std::min( (a)[1], (a)[2] ) ) )
 
 #define VectorInverse(a) \
 { \
@@ -88,8 +81,8 @@ extern const vec3_t vec3_origin;
     (dest)[2] = (a)[2] + scale * (b)[2]; \
 }
 #define VectorLength(a)  sqrt((double) ((double)((a)[0] * (a)[0]) + (double)( (a)[1] * (a)[1]) + (double)( (a)[2] * (a)[2])) )
-#define VectorCompareMinimum(a,b,c) { (c)[0] = min((a)[0], (b)[0]); (c)[1] = min((a)[1], (b)[1]); (c)[2] = min((a)[2], (b)[2]); }
-#define VectorCompareMaximum(a,b,c) { (c)[0] = max((a)[0], (b)[0]); (c)[1] = max((a)[1], (b)[1]); (c)[2] = max((a)[2], (b)[2]); }
+#define VectorCompareMinimum(a,b,c) { (c)[0] = std::min((a)[0], (b)[0]); (c)[1] = std::min((a)[1], (b)[1]); (c)[2] = std::min((a)[2], (b)[2]); }
+#define VectorCompareMaximum(a,b,c) { (c)[0] = std::max((a)[0], (b)[0]); (c)[1] = std::max((a)[1], (b)[1]); (c)[2] = std::max((a)[2], (b)[2]); }
 
 inline vec_t   VectorNormalize(vec3_t v)
 {
