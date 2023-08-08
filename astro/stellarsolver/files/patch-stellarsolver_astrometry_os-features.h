--- stellarsolver/astrometry/os-features.h.orig	2022-07-29 16:11:55 UTC
+++ stellarsolver/astrometry/os-features.h
@@ -110,7 +110,7 @@
 
 #if NEED_DECLARE_QSORT_R
 //// NOTE: this declaration must match os-features-test.c .
-void qsort_r(void *base, size_t nmemb, size_t sz,
+void (qsort_r)(void *base, size_t nmemb, size_t sz,
              void *userdata,
              int (*compar)(void *, const void *, const void *));
 #endif
