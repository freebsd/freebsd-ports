--- soundcard/simd.h.orig	2015-05-04 17:48:55 UTC
+++ soundcard/simd.h
@@ -54,6 +54,10 @@
 
 #if !defined(USEMMX) && !defined(USEVIS)
 
+#if __clang__ > 0
+#define only_inline inline
+#endif
+
 only_inline void initsimd(int enable)
 {
 }
