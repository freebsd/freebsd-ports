--- sysdeps/freebsd/procmap.c.orig	Mon Dec 12 05:09:39 2005
+++ sysdeps/freebsd/procmap.c	Fri Jan 20 16:28:33 2006
@@ -108,14 +108,16 @@ glibtop_get_proc_map_p (glibtop *server,
 #else
 	struct vm_object object;
 #endif
-	glibtop_map_entry *maps;
+	GArray *maps = g_array_sized_new(FALSE, FALSE,
+					 sizeof(glibtop_map_entry),
+					 100);
 #if defined __FreeBSD__
 	struct vnode vnode;
 #if __FreeBSD_version < 500039
 	struct inode inode;
 #endif
 #endif
-	int count, i = 0;
+	int count;
 	int update = 0;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_MAP), 0);
@@ -123,15 +125,15 @@ glibtop_get_proc_map_p (glibtop *server,
 	memset (buf, 0, sizeof (glibtop_proc_map));
 
 	/* It does not work for the swapper task. */
-	if (pid == 0) return NULL;
+	if (pid == 0) return (glibtop_map_entry*) g_array_free(maps, TRUE);
 
 	glibtop_suid_enter (server);
 
 	/* Get the process data */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
 	if ((pinfo == NULL) || (count < 1)) {
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
-		return NULL;
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
+		return (glibtop_map_entry*) g_array_free(maps, TRUE);
 	}
 
 	/* Now we get the memory maps. */
@@ -159,8 +161,6 @@ glibtop_get_proc_map_p (glibtop *server,
 
 	buf->total = buf->number * buf->size;
 
-	maps = g_malloc0(buf->total);
-
 	buf->flags = _glibtop_sysdeps_proc_map;
 
 	/* Walk through the `vm_map_entry' list ... */
@@ -170,6 +170,10 @@ glibtop_get_proc_map_p (glibtop *server,
 	 * to OBJT_DEFAULT so if seems this really works. */
 
 	do {
+		glibtop_map_entry *mentry;
+		unsigned long inode, dev;
+		guint len;
+
 		if (update) {
 			if (kvm_read (server->machine.kd,
 				      (unsigned long) entry.next,
@@ -197,22 +201,6 @@ glibtop_get_proc_map_p (glibtop *server,
 #endif
 #endif
 
-		maps [i].flags  = _glibtop_sysdeps_map_entry;
-
-		maps [i].start  = entry.start;
-		maps [i].end    = entry.end;
-		maps [i].offset = entry.offset;
-
-		maps [i].perm   = 0;
-
-		if (entry.protection & VM_PROT_READ)
-			maps [i].perm |= GLIBTOP_MAP_PERM_READ;
-		if (entry.protection & VM_PROT_WRITE)
-			maps [i].perm |= GLIBTOP_MAP_PERM_WRITE;
-		if (entry.protection & VM_PROT_EXECUTE)
-			maps [i].perm |= GLIBTOP_MAP_PERM_EXECUTE;
-
-		i++;
 
 #if defined(__NetBSD__) && (__NetBSD_Version__ >= 104000000)
 		if (!entry.object.uvm_obj)
@@ -224,7 +212,7 @@ glibtop_get_proc_map_p (glibtop *server,
 			      (unsigned long) entry.object.uvm_obj,
 			      &vnode, sizeof (vnode)) != sizeof (vnode)) {
 			glibtop_warn_io_r (server, "kvm_read (vnode)");
-			return NULL;
+			return (glibtop_map_entry*) g_array_free(maps, TRUE);
 		}
 #else
 		if (!entry.object.vm_object)
@@ -251,8 +239,8 @@ glibtop_get_proc_map_p (glibtop *server,
 			      &inode, sizeof (inode)) != sizeof (inode))
 			glibtop_error_io_r (server, "kvm_read (inode)");
 
-		maps [i-1].inode  = inode.i_number;
-		maps [i-1].device = inode.i_dev;
+		inode  = inode.i_number;
+		dev = inode.i_dev;
 #endif
 
 
@@ -274,8 +262,8 @@ glibtop_get_proc_map_p (glibtop *server,
                switch (vnode.v_type) {
                    case VREG:
 #if __FreeBSD_version < 600006
-                       maps [i-1].inode = vnode.v_cachedid;
-                       maps [i-1].device = vnode.v_cachedfs;
+                       inode = vnode.v_cachedid;
+                       dev = vnode.v_cachedfs;
 #endif
                    default:
                    continue;
@@ -289,11 +277,37 @@ glibtop_get_proc_map_p (glibtop *server,
 			      &inode, sizeof (inode)) != sizeof (inode))
 			glibtop_error_io_r (server, "kvm_read (inode)");
 
-		maps [i-1].inode  = inode.i_number;
-		maps [i-1].device = inode.i_dev;
+		inode  = inode.i_number;
+		dev = inode.i_dev;
 #endif
 #endif
+		len = maps->len;
+		g_array_set_size(maps, len + 1);
+		mentry = &g_array_index(maps, glibtop_map_entry, len);
+
+		mentry->flags  = _glibtop_sysdeps_map_entry;
+
+		mentry->start  = (guint64) entry.start;
+		mentry->end    = (guint64) entry.end;
+		mentry->offset = (guint64) entry.offset;
+		mentry->device = (guint64) dev;
+		mentry->inode  = (guint64) inode;
+
+		mentry->perm   = (guint64) 0;
+
+		if (entry.protection & VM_PROT_READ)
+			mentry->perm |= GLIBTOP_MAP_PERM_READ;
+		if (entry.protection & VM_PROT_WRITE)
+			mentry->perm |= GLIBTOP_MAP_PERM_WRITE;
+		if (entry.protection & VM_PROT_EXECUTE)
+			mentry->perm |= GLIBTOP_MAP_PERM_EXECUTE;
 	} while (entry.next != first);
 
-	return maps;
+	buf->flags = _glibtop_sysdeps_proc_map;
+
+	buf->number = maps->len;
+	buf->size = sizeof (glibtop_map_entry);
+	buf->total = buf->number * buf->size;
+
+	return (glibtop_map_entry*) g_array_free(maps, FALSE);
 }
