--- src/fs/iwfile.c.orig	2018-04-12 13:48:26 UTC
+++ src/fs/iwfile.c
@@ -92,7 +92,7 @@ static iwrc _iwfs_sync(struct IWFS_FILE *f, iwfs_sync_
     if (fcntl(wf->fh, F_FULLFSYNC) == -1) {
       return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
     }
-#else
+#elif defined(__FreeBSD_version) && __FreeBSD_version > 1100501
     if (fdatasync(wf->fh) == -1) {
       return iwrc_set_errno(IW_ERROR_IO_ERRNO, errno);
     }
