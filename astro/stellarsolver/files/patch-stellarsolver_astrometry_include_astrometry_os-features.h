--- stellarsolver/astrometry/include/astrometry/os-features.h.orig	2026-06-24 17:39:22 UTC
+++ stellarsolver/astrometry/include/astrometry/os-features.h
@@ -108,23 +108,6 @@
    -Ubuntu 8.10
 */
 
-#if NEED_DECLARE_QSORT_R
-//// NOTE: this declaration must match os-features-test.c .
-void qsort_r(void *base, size_t nmemb, size_t sz,
-             void *userdata,
-             int (*compar)(void *, const void *, const void *));
-#endif
-
-#if NEED_SWAP_QSORT_R
-#define QSORT_R(a,b,c,d,e) qsort_r(a,b,c,e,d)
-#define QSORT_COMPARISON_FUNCTION(func, thunk, v1, v2) func(v1, v2, thunk)
-
-#else
-#define QSORT_R qsort_r
-#define QSORT_COMPARISON_FUNCTION(func, thunk, v1, v2) func(thunk, v1, v2)
-
-#endif
-
 //# Modified for the StellarSolver Internal Library for thread safety
 // Portable reentrant wrappers for platform-specific APIs.
 // Each wraps the platform's reentrant variant behind a uniform interface.
