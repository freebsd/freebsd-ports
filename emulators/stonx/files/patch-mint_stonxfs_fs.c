--- mint/mint_stonxfs_fs.c.orig	2004-08-15 13:25:24 UTC
+++ mint/mint_stonxfs_fs.c
@@ -43,6 +43,8 @@
 #elif defined(STATFS_USE_STATFS_VMOUNT)
 #include <sys/statfs.h>
 #include <sys/vmount.h>
+#elif defined(STATFS_USE_STATVFS)
+#include <sys/statvfs.h>
 #else
 #include <sys/vfs.h>  
 #endif
