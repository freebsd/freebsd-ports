--- src/fs/iwfile.c.orig	2018-05-02 10:28:14 UTC
+++ src/fs/iwfile.c
@@ -97,7 +97,7 @@ static iwrc _iwfs_sync(struct IWFS_FILE *f, iwfs_sync_
     if (fcntl(impl->fh, F_FULLFSYNC) == -1) {
       return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
     }
-#else
+#elif defined(__FreeBSD_version) && __FreeBSD_version > 1100501
     if (fdatasync(impl->fh) == -1) {
       return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
     }
