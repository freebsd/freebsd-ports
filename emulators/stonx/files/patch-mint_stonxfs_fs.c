--- mint/mint_stonxfs_fs.c.orig	2004-08-15 15:25:24.000000000 +0200
+++ mint/mint_stonxfs_fs.c	2010-04-03 09:52:51.000000000 +0200
@@ -43,6 +43,8 @@
 #elif defined(STATFS_USE_STATFS_VMOUNT)
 #include <sys/statfs.h>
 #include <sys/vmount.h>
+#elif defined(STATFS_USE_STATVFS)
+#include <sys/statvfs.h>
 #else
 #include <sys/vfs.h>  
 #endif
