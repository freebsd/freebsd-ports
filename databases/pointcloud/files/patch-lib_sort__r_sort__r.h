--- lib/sort_r/sort_r.h.orig	2022-09-12 07:14:10 UTC
+++ lib/sort_r/sort_r.h
@@ -27,10 +27,10 @@ void sort_r(void *base, size_t nel, size_t width,
 #define _SORT_R_INLINE inline
 
 #if (defined __APPLE__ || defined __MACH__ || defined __DARWIN__ || \
-     defined __FreeBSD__ || defined __DragonFly__)
+     (defined __FreeBSD__ && !defined(qsort_r)) || defined __DragonFly__)
 #  define _SORT_R_BSD
 #elif (defined _GNU_SOURCE || defined __gnu_hurd__ || defined __GNU__ || \
-       defined __linux__ || (defined __MINGW32__ && !defined __MINGW64_VERSION_MAJOR) || defined __GLIBC__)
+       defined __linux__ || (defined __MINGW32__ && !defined __MINGW64_VERSION_MAJOR) || defined __GLIBC__ || (defined (__FreeBSD__) && defined(qsort_r)))
 #  define _SORT_R_LINUX
 #elif (defined _WIN32 || defined _WIN64 || defined __WINDOWS__)
 #  define _SORT_R_WINDOWS
@@ -170,7 +170,7 @@ static _SORT_R_INLINE void sort_r_simple(void *base, s
   #if defined _SORT_R_LINUX
 
     typedef int(* __compar_d_fn_t)(const void *, const void *, void *);
-    extern void qsort_r(void *base, size_t nel, size_t width,
+    extern void (qsort_r)(void *base, size_t nel, size_t width,
                         __compar_d_fn_t __compar, void *arg)
       __attribute__((nonnull (1, 4)));
 
