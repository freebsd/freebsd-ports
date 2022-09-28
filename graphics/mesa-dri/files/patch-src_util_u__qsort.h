--- src/util/u_qsort.h.orig	2022-03-18 19:26:47 UTC
+++ src/util/u_qsort.h
@@ -56,8 +56,10 @@ util_qsort_r(void *base, size_t nmemb, size_t size,
              int (*compar)(const void *, const void *, void *),
              void *arg)
 {
-#if HAVE_QSORT_R
-#  if DETECT_OS_APPLE || DETECT_OS_BSD
+#if HAVE_GNU_QSORT_R
+   /* GNU extension added in glibc 2.8 */
+   qsort_r(base, nmemb, size, compar, arg);
+#elif HAVE_BSD_QSORT_R
    /* BSD/macOS qsort_r takes "arg" before the comparison function and it
     * pass the "arg" before the elements.
     */
@@ -66,10 +68,6 @@ util_qsort_r(void *base, size_t nmemb, size_t size,
       arg
    };
    qsort_r(base, nmemb, size, &data, util_qsort_adapter);
-#  else
-   /* GNU extension added in glibc 2.8 */
-   qsort_r(base, nmemb, size, compar, arg);
-#  endif
 #elif HAVE_QSORT_S
 #  ifdef _WIN32
    /* MSVC/MinGW qsort_s takes "arg" after the comparison function and it
