--- sysdeps/freebsd/procmap.c.orig
+++ sysdeps/freebsd/procmap.c
@@ -20,12 +20,32 @@
 */
 
 #include <config.h>
+
+/*
+ * FreeBSD-16 specific stuff that shouldn't hurt earlier FreeBSD:
+ *
+ * Need sys/event.h early with _KERNEL, before glibtop/procmap.h.
+ * This gets us macros for some inline vnode functions that crop up
+ * with _KERNEL later.
+ *
+ * After that, we need to neuter MPASS by including kassert.h.  Last,
+ * a boolean_t conflict appears (sys/types.h vs vm/vm.h), so whack it as well.
+ */
+#define _KERNEL
+#include <sys/types.h>
+#include <sys/event.h>
+#include <sys/kassert.h>
+#undef _KERNEL
+#define HAVE_BOOLEAN /* until vm/vm.h is cleaned-up */
+
 #include <glibtop.h>
 #include <glibtop/error.h>
 #include <glibtop/procmap.h>
 
 #include <glibtop_suid.h>
 
+#include <stdbool.h>
+
 #include <kvm.h>
 #include <sys/param.h>
 #include <sys/proc.h>
@@ -43,6 +63,7 @@
 #define _WANT_FILE
 #include <sys/file.h>
 #undef _WANT_FILE
+#include <sys/systm.h> /* early and without _KERNEL, for FreeBSD 16 */
 #else
 #define _KERNEL
 #include <sys/file.h>
@@ -51,12 +72,14 @@
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
@@ -100,7 +123,7 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, struct vnode *vnode,
         *inum = 0;
         *dev = 0;
 
-        if (kvm_read (server->machine->kd, (gulong) &vnode->v_tag,
+        if (kvm_read (server->machine->kd, (gulong) &vnode->v_lock.lock_object.lo_name,
  	             (char *) &tagptr, sizeof (tagptr)) != sizeof (tagptr) ||
             kvm_read (server->machine->kd, (gulong) tagptr,
 		     (char *) tagstr, sizeof (tagstr)) != sizeof (tagstr))
@@ -120,7 +143,7 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, struct vnode *vnode,
                 return;
         }
 
-        if (kvm_read (server->machine->kd, (gulong) VTOI(vn), (char *) &inode,
+        if (kvm_read (server->machine->kd, (gulong) ((struct inode *)(vn)->v_data), (char *) &inode,
  	              sizeof (inode)) != sizeof (inode))
         {
                 glibtop_warn_io_r (server, "kvm_read (inode)");
