--- sysdeps/freebsd/procmap.c.orig	2015-08-17 18:59:37 UTC
+++ sysdeps/freebsd/procmap.c
@@ -52,6 +52,8 @@
 #include <sys/mount.h>
 #include <ufs/ufs/quota.h>
 #include <ufs/ufs/inode.h>
+#include <ufs/ufs/extattr.h>
+#include <ufs/ufs/ufsmount.h>
 #include <fs/devfs/devfs.h>
 #if (__FreeBSD_version >= 600006) || defined(__FreeBSD_kernel__)
 #include <fs/devfs/devfs_int.h>
@@ -86,6 +88,8 @@ _glibtop_sysdeps_freebsd_dev_inode (glib
         struct cdev_priv priv;
 #if __FreeBSD_version < 800039
         struct cdev si;
+#else
+        struct ufsmount um;
 #endif
 
         *inum = 0;
@@ -167,7 +171,9 @@ _glibtop_sysdeps_freebsd_dev_inode (glib
 
 
 #if (__FreeBSD_version >= 800039) || (__FreeBSD_kernel_version >= 800039)
-        if (kvm_read (server->machine->kd, (gulong) cdev2priv(inode.i_dev), (char *) &priv,
+        if (kvm_read (server->machine->kd, (gulong) inode.i_ump, (char *) &um,
+		      sizeof (um)) != sizeof (um) ||
+            kvm_read (server->machine->kd, (gulong) cdev2priv(um.um_dev), (char *) &priv,
 		      sizeof (priv))
 #else
         if (kvm_read (server->machine->kd, (gulong) inode.i_dev, (char *) &si,
