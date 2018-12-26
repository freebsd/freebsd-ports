--- include/gc_pthread_redirects.h.orig	2018-12-23 21:28:41 UTC
+++ include/gc_pthread_redirects.h
@@ -53,12 +53,8 @@
 # endif /* !GC_NO_DLOPEN */
 
 # ifndef GC_NO_PTHREAD_SIGMASK
-#   if defined(GC_PTHREAD_SIGMASK_NEEDED) \
-        || defined(_BSD_SOURCE) || defined(_GNU_SOURCE) \
-        || (_POSIX_C_SOURCE >= 199506L) || (_XOPEN_SOURCE >= 500)
       GC_API int GC_pthread_sigmask(int /* how */, const sigset_t *,
                                     sigset_t * /* oset */);
-#   endif
 # endif /* !GC_NO_PTHREAD_SIGMASK */
 
 # ifndef GC_PTHREAD_CREATE_CONST
