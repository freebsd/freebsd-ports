--- src/fsio.c.orig	2020-07-21 17:25:51 UTC
+++ src/fsio.c
@@ -70,6 +70,10 @@ static size_t copy_iter_count = 0;
 # define NFS_SUPER_MAGIC	0x6969
 #endif
 
+#if defined(__FreeBSD__)
+#include <dlfcn.h>
+#endif
+
 typedef struct fsopendir fsopendir_t;
 
 struct fsopendir {
@@ -1109,7 +1113,30 @@ static int sys_fsetxattr(pool *p, pr_fh_t *fh, int fd,
   return res;
 }
 
+#if defined(__FreeBSD__)
+static int
+enter_freebsd_restricted_mode()
+{
+  typedef void frmode_t();
+  frmode_t *frmode;
+
+  frmode = (frmode_t *)dlfunc(
+    RTLD_NEXT, "__FreeBSD_libc_enter_restricted_mode");
+  if (frmode == NULL) {
+    pr_log_pri(PR_LOG_ERR,
+      "error: FreeBSD with vulnerable chroot (FreeBSD-SA-11:07.chroot)");
+    return 1;
+  }
+  frmode();
+  return 0;
+}
+#endif
+
 static int sys_chroot(pr_fs_t *fs, const char *path) {
+#if defined(__FreeBSD__)
+  if (enter_freebsd_restricted_mode() != 0)
+    return -1;
+#endif
   if (chroot(path) < 0) {
     return -1;
   }
