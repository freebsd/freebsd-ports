--- src/platform/unix/unix.c.orig	2021-09-03 09:03:05 UTC
+++ src/platform/unix/unix.c
@@ -355,7 +355,7 @@ iwrc iwp_fdatasync(HANDLE fh) {
   if (fcntl(fh, F_FULLFSYNC) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }
-#else
+#elif defined(__FreeBSD_version)
   if (fdatasync(fh) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }
