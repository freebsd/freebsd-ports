--- common/dconf-shmdir.c.orig	2010-10-21 13:46:17.000000000 +0200
+++ common/dconf-shmdir.c	2010-10-21 13:47:46.000000000 +0200
@@ -21,8 +21,13 @@
 
 #include "dconf-shmdir.h"
 
+#ifdef __linux__
 #include <sys/statfs.h>
 #include <sys/vfs.h>
+#elif __FreeBSD__
+#include <sys/param.h>
+#include <sys/mount.h>
+#endif
 #include <errno.h>
 
 #ifndef NFS_SUPER_MAGIC
