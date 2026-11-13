--- libs/simde/simde/simde-math.h.orig	2024-04-30 16:35:50 UTC
+++ libs/simde/simde/simde-math.h
@@ -1266,8 +1266,9 @@ simde_math_fpclass(double v, const int imm8) {

 #if !defined(simde_math_roundeven)
   #if \
-     ((!defined(HEDLEY_EMSCRIPTEN_VERSION) || HEDLEY_EMSCRIPTEN_VERSION_CHECK(3, 1, 43)) && HEDLEY_HAS_BUILTIN(__builtin_roundeven)) || \
-      HEDLEY_GCC_VERSION_CHECK(10,0,0)
+     ((!defined(HEDLEY_EMSCRIPTEN_VERSION) || HEDLEY_EMSCRIPTEN_VERSION_CHECK(3, 1, 43)) && \
+       HEDLEY_HAS_BUILTIN(__builtin_roundeven) && \
+       (defined(__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 25))))
     #define simde_math_roundeven(v) __builtin_roundeven(v)
   #elif defined(simde_math_round) && defined(simde_math_fabs)
     static HEDLEY_INLINE
@@ -1286,8 +1287,9 @@ simde_math_fpclass(double v, const int imm8) {

 #if !defined(simde_math_roundevenf)
   #if \
-     ((!defined(HEDLEY_EMSCRIPTEN_VERSION) || HEDLEY_EMSCRIPTEN_VERSION_CHECK(3, 1, 43)) && HEDLEY_HAS_BUILTIN(__builtin_roundevenf)) || \
-      HEDLEY_GCC_VERSION_CHECK(10,0,0)
+     ((!defined(HEDLEY_EMSCRIPTEN_VERSION) || HEDLEY_EMSCRIPTEN_VERSION_CHECK(3, 1, 43)) && \
+       HEDLEY_HAS_BUILTIN(__builtin_roundevenf) && \
+       (defined(__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 25))))
     #define simde_math_roundevenf(v) __builtin_roundevenf(v)
   #elif defined(simde_math_roundf) && defined(simde_math_fabsf)
     static HEDLEY_INLINE
