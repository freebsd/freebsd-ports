--- src/fsio.c.orig	2010-04-12 12:00:00.000000000 -0700
+++ src/fsio.c	2011-12-16 15:12:07.799166185 -0800
@@ -50,6 +50,8 @@
 # include <acl/libacl.h>
 #endif
 
+#include <unistd.h>
+
 typedef struct fsopendir fsopendir_t;
 
 struct fsopendir {
@@ -287,6 +289,7 @@
 static int sys_chroot(pr_fs_t *fs, const char *path) {
   if (chroot(path) < 0)
     return -1;
+  __FreeBSD_libc_enter_restricted_mode();
 
   session.chroot_path = (char *) path;
   return 0;
