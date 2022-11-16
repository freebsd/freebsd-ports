--- src/jbi/sort_r.h.orig	2022-02-23 10:00:23 UTC
+++ src/jbi/sort_r.h
@@ -25,10 +25,11 @@
 #define _SORT_R_INLINE inline
 
 #if (  defined __APPLE__ || defined __MACH__ || defined __DARWIN__    \
-    || defined __FreeBSD__ || defined __DragonFly__) && defined JB_HAVE_QSORT_R
+    || (defined __FreeBSD__ && !defined(qsort_r)) || defined __DragonFly__) && defined JB_HAVE_QSORT_R
 #  define _SORT_R_BSD
 #elif (  defined _GNU_SOURCE || defined __gnu_hurd__ || defined __GNU__    \
-      || defined __linux__ || defined __MINGW32__ || defined __GLIBC__) && defined JB_HAVE_QSORT_R
+      || defined __linux__ || defined __MINGW32__ || defined __GLIBC__ \
+      || (defined (__FreeBSD__) && defined(qsort_r))) && defined JB_HAVE_QSORT_R
 #  define _SORT_R_LINUX
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
@@ -255,7 +256,7 @@ static _SORT_R_INLINE void sort_r(
   #if defined _SORT_R_BSD
 
 /* Ensure qsort_r is defined */
-extern void qsort_r(
+extern void (qsort_r)(
   void *base, size_t nel, size_t width, void *thunk,
   int (*compar)(void *_thunk,
                 const void *_a, const void *_b));
@@ -283,7 +284,7 @@ typedef int (*__compar_d_fn_t)(const void*, const void
   #if defined _SORT_R_LINUX
 
 typedef int (*__compar_d_fn_t)(const void*, const void*, void*);
-extern void qsort_r(
+extern void (qsort_r)(
   void *base, size_t nel, size_t width,
   __compar_d_fn_t __compar, void *arg)
 __attribute__((nonnull(1, 4)));
