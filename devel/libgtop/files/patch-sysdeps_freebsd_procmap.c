--- sysdeps/freebsd/procmap.c.orig	2019-02-04 20:15:22 UTC
+++ sysdeps/freebsd/procmap.c
@@ -51,14 +51,15 @@
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
 
-
 #if (__FreeBSD_version >= 1101001)
 #define _KERNEL
 #include <ufs/ufs/extattr.h>
@@ -95,12 +96,14 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, s
         struct cdev_priv priv;
 #if __FreeBSD_version < 800039
         struct cdev si;
+#else
+        struct ufsmount um;
 #endif
 
         *inum = 0;
         *dev = 0;
 
-        if (kvm_read (server->machine->kd, (gulong) &vnode->v_tag,
+        if (kvm_read (server->machine->kd, (gulong) &vnode->v_lock.lock_object.lo_name,
  	             (char *) &tagptr, sizeof (tagptr)) != sizeof (tagptr) ||
             kvm_read (server->machine->kd, (gulong) tagptr,
 		     (char *) tagstr, sizeof (tagstr)) != sizeof (tagstr))
@@ -120,7 +123,7 @@ _glibtop_sysdeps_freebsd_dev_inode (glibtop *server, s
                 return;
         }
 
-        if (kvm_read (server->machine->kd, (gulong) VTOI(vn), (char *) &inode,
+        if (kvm_read (server->machine->kd, (gulong) ((struct inode *)(vn)->v_data), (char *) &inode,
  	              sizeof (inode)) != sizeof (inode))
         {
                 glibtop_warn_io_r (server, "kvm_read (inode)");
@@ -231,6 +234,32 @@ _glibtop_init_proc_map_p (glibtop *server)
         server->sysdeps.proc_map = _glibtop_sysdeps_proc_map;
 }
 
+static int
+vm_map_reader(void *token, vm_map_entry_t addr, vm_map_entry_t dest)
+{
+	kvm_t *kd;
+
+	kd = (kvm_t *)token;
+	return (kvm_read (kd, (gulong) addr, dest, sizeof(*dest)) == sizeof(*dest));
+}
+
+#if (__FreeBSD_version < 1300062)
+typedef int vm_map_entry_reader(void *token, vm_map_entry_t addr,
+    vm_map_entry_t dest);
+
+static inline vm_map_entry_t
+vm_map_entry_read_succ(void *token, struct vm_map_entry *const clone,
+     vm_map_entry_reader reader)
+{
+	vm_map_entry_t next;
+
+	next = clone->next;
+	if (!reader (token, next, clone))
+		return (NULL);
+	return (next);
+}
+#endif
+
 /* Provides detailed information about a process. */
 
 glibtop_map_entry *
@@ -238,13 +267,12 @@ glibtop_get_proc_map_p (glibtop *server, glibtop_proc_
                         pid_t pid)
 {
         struct kinfo_proc *pinfo;
-        struct vm_map_entry entry, *first;
+        struct vm_map_entry entry;
         struct vmspace vmspace;
         struct vm_object object;
         GArray *maps;
         struct vnode vnode;
-        int count;
-        int update = 0;
+        int i, count;
 
         memset (buf, 0, sizeof (glibtop_proc_map));
 
@@ -273,16 +301,6 @@ glibtop_get_proc_map_p (glibtop *server, glibtop_proc_
                 return NULL;
         }
 
-        first = vmspace.vm_map.header.next;
-
-        if (kvm_read (server->machine->kd,
-                        (gulong) vmspace.vm_map.header.next,
-                        (char *) &entry, sizeof (entry)) != sizeof (entry)) {
-                glibtop_warn_io_r (server, "kvm_read (entry)");
-		glibtop_suid_leave (server);
-                return NULL;
-        }
-
         /* Walk through the `vm_map_entry' list ... */
 
         /* I tested this a few times with `mmap'; as soon as you write
@@ -292,21 +310,17 @@ glibtop_get_proc_map_p (glibtop *server, glibtop_proc_
         maps = g_array_sized_new(FALSE, FALSE, sizeof(glibtop_map_entry),
                                  vmspace.vm_map.nentries);
 
-        do {
+	entry = vmspace.vm_map.header;
+        for (i = 0; i < vmspace.vm_map.nentries; i++) {
                 glibtop_map_entry *mentry;
                 guint64 inum, dev;
                 guint len;
 
-                if (update) {
-                        if (kvm_read (server->machine->kd,
-                                        (gulong) entry.next,
-                                        (char *) &entry, sizeof (entry)) != sizeof (entry)) {
-                                glibtop_warn_io_r (server, "kvm_read (entry)");
-                                continue;
-                        }
-                } else {
-                        update = 1;
-                }
+		if (!vm_map_entry_read_succ(server->machine->kd, &entry, vm_map_reader)) {
+			glibtop_warn_io_r (server, "kvm_read (entry)");
+			glibtop_suid_leave (server);
+			return NULL;
+		}
 
                 if (entry.eflags & (MAP_ENTRY_IS_SUB_MAP))
                         continue;
@@ -377,7 +391,7 @@ glibtop_get_proc_map_p (glibtop *server, glibtop_proc_
                 if (entry.protection & VM_PROT_EXECUTE)
                         mentry->perm |= GLIBTOP_MAP_PERM_EXECUTE;
 
-        } while (entry.next != first);
+        }
 
         glibtop_suid_leave (server);
 
