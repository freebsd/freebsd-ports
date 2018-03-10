--- lib/file/fileTempPosix.c.orig	2017-12-15 21:11:49 UTC
+++ lib/file/fileTempPosix.c
@@ -203,12 +203,17 @@ FileGetUserName(uid_t uid)  // IN:
 #if defined(__APPLE__)
    memPoolSize = _PASSWORD_LEN;
 #else
+   errno = 0;
    memPoolSize = sysconf(_SC_GETPW_R_SIZE_MAX);
 
-   if (memPoolSize <= 0) {
+   if ((errno != 0) || (memPoolSize == 0)) {
       Warning("%s: sysconf(_SC_GETPW_R_SIZE_MAX) failed.\n", __FUNCTION__);
 
       return NULL;
+   }
+
+   if (memPoolSize == -1) {  // Unlimited; pick something reasonable
+      memPoolSize = 16 * 1024;
    }
 #endif
 
