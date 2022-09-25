--- stellarsolver/astrometry/util/os-features-test.c.orig	2022-07-29 16:11:55 UTC
+++ stellarsolver/astrometry/util/os-features-test.c
@@ -14,7 +14,11 @@ int main() {
 }
 #endif
 
-#ifdef TEST_QSORT_R
+#ifdef TEST_BSD_QSORT_R
+void (qsort_r)(void *base, size_t nmemb, size_t sz,
+             void *userdata,
+             int (*compar)(void *, const void *, const void *));
+
 static int cmp(void* u, const void* a, const void* b) {
     return 0;
 }
@@ -22,51 +26,22 @@ int main() {
     int array;
     int baton;
     qsort_r(&array, 1, sizeof(int), &baton, cmp);
-    //printf("#define NEED_QSORT_R 0\n");
     return 0;
 }
 #endif
 
-#ifdef TEST_DECLARE_QSORT_R
-// Test whether just declaring qsort_r as we do causes a compile failure.
+#ifdef TEST_GNU_QSORT_R
+void (qsort_r)(void *base, size_t nmemb, size_t sz,
+             int (*compar)(const void *, const void *, void *),
+             void *userdata);
 
-void qsort_r(void *base, size_t nmemb, size_t sz,
-             void *userdata,
-             int (*compar)(void *, const void *, const void *));
-
-int main() {
-    //printf("#define NEED_DECLARE_QSORT_R 1\n");
+static int cmp(const void* a, const void* b, void* u) {
     return 0;
 }
-#endif
-
-#ifdef TEST_SWAP_QSORT_R
-// Use the result of TEST_DECLARE_QSORT_R and TEST_NEED_QSORT_R, or else
-// this test will fail with a warning about undefined qsort_r
-// Include .c rather than .h because we test with:
-//     gcc -o (exec) os-features-test.c
-// and if NEED_QSORT_R, os-features.c includes qsort_reentrant.c
-#include "os-features-config.h.tmp"
-#define DONT_INCLUDE_OS_FEATURES_CONFIG_H 1
-#include "os-features.c"
-#undef DONT_INCLUDE_OS_FEATURES_CONFIG_H
-// Test whether qsort_r works unswapped. (ie, qsort_r matches the definition of
-// QSORT_R defined in the os-features.h documentation.)
-static int sortfunc(void* thunk, const void* v1, const void* v2) {
-    const int* i1 = v1;
-    const int* i2 = v2;
-    if (*i1 < *i2)
-        return -1;
-    if (*i1 > *i2)
-        return 1;
-    return 0;
-}
 int main() {
-    int array[] = { 4, 17, 88, 34, 12, 12, 17 };
-    int N = sizeof(array)/sizeof(int);
-    int mythunk = 42;
-    qsort_r(array, N, sizeof(int), &mythunk, sortfunc);
-    //printf("#define NEED_SWAP_QSORT_R 0\n");
+    int array;
+    int baton;
+    qsort_r(&array, 1, sizeof(int), cmp, &baton);
     return 0;
 }
 #endif
