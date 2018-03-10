--- include/gc_pthread_redirects.h.orig	2018-01-04 14:41:42 UTC
+++ include/gc_pthread_redirects.h
@@ -44,12 +44,8 @@
 
 # ifndef GC_NO_PTHREAD_SIGMASK
 #   include <signal.h>  /* needed anyway for proper redirection */
-#   if defined(GC_PTHREAD_SIGMASK_NEEDED) \
-        || defined(_BSD_SOURCE) || defined(_GNU_SOURCE) \
-        || (_POSIX_C_SOURCE >= 199506L) || (_XOPEN_SOURCE >= 500)
       GC_API int GC_pthread_sigmask(int /* how */, const sigset_t *,
                                     sigset_t * /* oset */);
-#   endif
 # endif /* !GC_NO_PTHREAD_SIGMASK */
 
 # ifndef GC_PTHREAD_CREATE_CONST
