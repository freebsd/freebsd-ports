Assume Clang supports x86 intrinsics up to FMA
https://github.com/xiph/flac/commit/90c0562d4eb302b01d9b82c75a7f6a66261c5546

--- src/libFLAC/include/private/cpu.h.orig	2022-09-21 18:57:31 UTC
+++ src/libFLAC/include/private/cpu.h
@@ -82,28 +82,14 @@
 #elif defined __clang__ && __has_attribute(__target__) /* clang */
   #define FLAC__SSE_TARGET(x) __attribute__ ((__target__ (x)))
   #define FLAC__FAST_MATH_TARGET(x) __attribute__ ((__target__ (x)))
-  #if __has_builtin(__builtin_ia32_maxps)
-    #define FLAC__SSE_SUPPORTED 1
-  #endif
-  #if __has_builtin(__builtin_ia32_pmuludq128)
-    #define FLAC__SSE2_SUPPORTED 1
-  #endif
-  #if __has_builtin(__builtin_ia32_pabsd128)
-    #define FLAC__SSSE3_SUPPORTED 1
-  #endif
-  #if __has_builtin(__builtin_ia32_pmuldq128)
-    #define FLAC__SSE4_1_SUPPORTED 1
-  #endif
+  #define FLAC__SSE_SUPPORTED 1
+  #define FLAC__SSE2_SUPPORTED 1
+  #define FLAC__SSSE3_SUPPORTED 1
+  #define FLAC__SSE4_1_SUPPORTED 1
   #ifdef FLAC__USE_AVX
-    #if __has_builtin(__builtin_ia32_maxps256)
-      #define FLAC__AVX_SUPPORTED 1
-    #endif
-    #if __has_builtin(__builtin_ia32_pabsd256)
-      #define FLAC__AVX2_SUPPORTED 1
-    #endif
-    #if __has_builtin(__builtin_ia32_vfmaddps)
-      #define FLAC__FMA_SUPPORTED 1
-    #endif
+    #define FLAC__AVX_SUPPORTED 1
+    #define FLAC__AVX2_SUPPORTED 1
+    #define FLAC__FMA_SUPPORTED 1
   #endif
 #elif defined __GNUC__ && !defined __clang__ && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9)) /* GCC 4.9+ */
   #define FLAC__SSE_TARGET(x) __attribute__ ((__target__ (x)))
