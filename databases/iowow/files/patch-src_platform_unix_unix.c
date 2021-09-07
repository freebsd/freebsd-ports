--- src/platform/unix/unix.c.orig	2021-09-03 09:03:05 UTC
+++ src/platform/unix/unix.c
@@ -355,7 +355,7 @@ iwrc iwp_fdatasync(HANDLE fh) {
   if (fcntl(fh, F_FULLFSYNC) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }
-#else
+#elif defined(__FreeBSD_version) && __FreeBSD_version > 1100501
   if (fdatasync(fh) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }
@@ -384,6 +384,10 @@ void iwp_set_current_thread_name(const char *name) {
 
 #if defined(__linux__)
   prctl(PR_SET_NAME, name);
+#elif defined(__FreeBSD__)
+  // We're using even more non-standard pthread_set_name_np() here
+  // because pthread_setname_np() is not available on FreeBSD 11.X.
+  pthread_set_name_np(pthread_self(), name);
 #elif defined(__NetBSD__)
   rv = pthread_setname_np(pthread_self(), "%s", (void*) name);
 #elif defined(__APPLE__)
