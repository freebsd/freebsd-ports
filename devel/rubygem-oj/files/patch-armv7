--- ext/oj/simd.h.orig	2025-09-14 12:52:05 UTC
+++ ext/oj/simd.h
@@ -1,10 +1,10 @@
 #ifndef OJ_SIMD_H
 #define OJ_SIMD_H
 
-#if defined(__ARM_NEON) || defined(__ARM_NEON__) || defined(__aarch64__) || defined(_M_ARM64)
+#if (defined(__ARM_NEON) || defined(__ARM_NEON__)) && (defined(__aarch64__) || defined(_M_ARM64))
 #define HAVE_SIMD_NEON 1
 #define SIMD_MINIMUM_THRESHOLD 6
 #include <arm_neon.h>
 #endif
 
-#endif /* OJ_SIMD_H */
\ No newline at end of file
+#endif /* OJ_SIMD_H */
