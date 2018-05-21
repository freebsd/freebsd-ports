--- src/platform/linux/linux.c.orig	2018-05-19 14:09:04 UTC
+++ src/platform/linux/linux.c
@@ -314,7 +314,7 @@ iwrc iwp_fdatasync(HANDLE fh) {
   if (fcntl(fh, F_FULLFSYNC) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }
-#else
+#elif defined(__FreeBSD_version) && __FreeBSD_version > 1100501
   if (fdatasync(fh) == -1) {
     return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
   }  
