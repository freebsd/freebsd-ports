--- Source/NSFileManager.m.orig	Fri Oct 25 11:32:59 2002
+++ Source/NSFileManager.m	Fri Oct 25 11:33:26 2002
@@ -100,9 +100,10 @@
 
 #ifdef HAVE_SYS_VFS_H
 # include <sys/vfs.h>
-# ifdef HAVE_SYS_STATVFS_H
-#  include <sys/statvfs.h>
-# endif
+#endif
+
+#ifdef HAVE_SYS_STATVFS_H
+# include <sys/statvfs.h>
 #endif
 
 #ifdef HAVE_SYS_STATFS_H
