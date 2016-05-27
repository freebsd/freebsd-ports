--- common/math/math.h.orig	2016-05-20 05:45:13 UTC
+++ common/math/math.h
@@ -179,7 +179,7 @@ namespace embree
   }
 #endif
 
-#if defined(__WIN32__)
+#if defined(__WIN32__) || defined(__FreeBSD__)
   __forceinline void sincosf(float x, float *s, float *c) {
     *s = sinf(x); *c = cosf(x);
   }
