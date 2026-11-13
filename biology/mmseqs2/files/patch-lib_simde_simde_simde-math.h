--- lib/simde/simde/simde-math.h.orig	2025-01-18 10:33:59 UTC
+++ lib/simde/simde/simde-math.h
@@ -1166,8 +1166,9 @@ simde_math_fpclassify(double v) {
 
 #if !defined(simde_math_roundeven)
   #if \
-      HEDLEY_HAS_BUILTIN(__builtin_roundeven) || \
-      HEDLEY_GCC_VERSION_CHECK(10,0,0)
+      (HEDLEY_HAS_BUILTIN(__builtin_roundeven) || \
+      HEDLEY_GCC_VERSION_CHECK(10,0,0)) && \
+      (defined(__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 25)))
     #define simde_math_roundeven(v) __builtin_roundeven(v)
   #elif defined(simde_math_round) && defined(simde_math_fabs)
     static HEDLEY_INLINE
@@ -1186,8 +1187,9 @@ simde_math_fpclassify(double v) {
 
 #if !defined(simde_math_roundevenf)
   #if \
-      HEDLEY_HAS_BUILTIN(__builtin_roundevenf) || \
-      HEDLEY_GCC_VERSION_CHECK(10,0,0)
+      (HEDLEY_HAS_BUILTIN(__builtin_roundevenf) || \
+      HEDLEY_GCC_VERSION_CHECK(10,0,0)) && \
+      (defined(__GLIBC__) && ((__GLIBC__ > 2) || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 25)))
     #define simde_math_roundevenf(v) __builtin_roundevenf(v)
   #elif defined(simde_math_roundf) && defined(simde_math_fabsf)
     static HEDLEY_INLINE
