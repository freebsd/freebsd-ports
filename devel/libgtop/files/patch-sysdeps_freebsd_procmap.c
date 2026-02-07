--- sysdeps/freebsd/procmap.c.orig	2023-01-15 10:43:14 UTC
+++ sysdeps/freebsd/procmap.c
@@ -26,6 +26,8 @@
 
 #include <glibtop_suid.h>
 
+#include <stdbool.h>
+
 #include <kvm.h>
 #include <sys/param.h>
 #include <sys/proc.h>
@@ -51,12 +53,14 @@
 #define _KERNEL
 #include <sys/mount.h>
 #include <ufs/ufs/quota.h>
-#include <ufs/ufs/inode.h>
+#include <ufs/ufs/extattr.h>
+#include <ufs/ufs/ufsmount.h>
 #include <fs/devfs/devfs.h>
 #if (__FreeBSD_version >= 600006) || defined(__FreeBSD_kernel__)
 #include <fs/devfs/devfs_int.h>
 #endif
 #undef _KERNEL
+#include <ufs/ufs/inode.h>
 
 
 #if (__FreeBSD_version >= 1101001)
@@ -100,7 +104,7 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, s
         *inum = 0;
         *dev = 0;
 
-        if (kvm_read (server->machine->kd, (gulong) &vnode->v_tag,
+        if (kvm_read (server->machine->kd, (gulong) &vnode->v_lock.lock_object.lo_name,
  	             (char *) &tagptr, sizeof (tagptr)) != sizeof (tagptr) ||
             kvm_read (server->machine->kd, (gulong) tagptr,
 		     (char *) tagstr, sizeof (tagstr)) != sizeof (tagstr))
@@ -120,7 +124,7 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, s
                 return;
         }
 
-        if (kvm_read (server->machine->kd, (gulong) VTOI(vn), (char *) &inode,
+        if (kvm_read (server->machine->kd, (gulong) ((struct inode *)(vn)->v_data), (char *) &inode,
  	              sizeof (inode)) != sizeof (inode))
         {
                 glibtop_warn_io_r (server, "kvm_read (inode)");
