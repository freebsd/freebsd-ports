--- common/math/math.h.orig	2016-05-20 05:45:13 UTC
+++ common/math/math.h
@@ -83,7 +83,7 @@ namespace embree
     return _mm_cvtss_f32(c);
   }
 
-#if !defined(__WIN32__)
+#if !defined(__WIN32__) && (!defined(_LIBCPP_VERSION) || _LIBCPP_VERSION < 3800)
   __forceinline float abs  ( const float x ) { return ::fabsf(x); }
   __forceinline float acos ( const float x ) { return ::acosf (x); }
   __forceinline float asin ( const float x ) { return ::asinf (x); }
@@ -179,7 +179,7 @@ namespace embree
   }
 #endif
 
-#if defined(__WIN32__)
+#if defined(__WIN32__) || defined(__FreeBSD__)
   __forceinline void sincosf(float x, float *s, float *c) {
     *s = sinf(x); *c = cosf(x);
   }
