--- modules/file-method.c.orig	Sun May 22 23:30:16 2005
+++ modules/file-method.c	Sun May 22 23:31:08 2005
@@ -66,6 +66,9 @@
 #if HAVE_SYS_VFS_H
 #include <sys/vfs.h>
 #elif HAVE_SYS_MOUNT_H
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #include <sys/mount.h>
 #endif
 
