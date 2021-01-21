--- src/serd_config.h.orig	2021-01-20 12:23:24 UTC
+++ src/serd_config.h
@@ -44,17 +44,6 @@
 #    endif
 #  endif
 
-// C99 and C++11: aligned_alloc()
-#  ifndef HAVE_ALIGNED_ALLOC
-#    if !defined(__APPLE__) && !defined(_WIN32)
-#      if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
-#        define HAVE_ALIGNED_ALLOC
-#      elif defined(__cplusplus) && __cplusplus >= 201103L)
-#        define HAVE_ALIGNED_ALLOC
-#      endif
-#    endif
-#  endif
-
 // POSIX.1-2001: fileno()
 #  ifndef HAVE_FILENO
 #    if defined(_POSIX_VERSION) && _POSIX_VERSION >= 200112L
@@ -87,12 +76,6 @@
   and this header is always required by any code that checks for features, even
   if the build system defines them all.
 */
-
-#ifdef HAVE_ALIGNED_ALLOC
-#  define USE_ALIGNED_ALLOC 1
-#else
-#  define USE_ALIGNED_ALLOC 0
-#endif
 
 #ifdef HAVE_FILENO
 #  define USE_FILENO 1
