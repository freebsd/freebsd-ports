--- sysdeps/freebsd/procmem.c.orig	Fri May 28 03:56:49 1999
+++ sysdeps/freebsd/procmem.c	Sun Sep  7 21:37:38 2003
@@ -137,6 +137,23 @@
 		return;
 	}
 
+#if __FreeBSD_version >= 500013
+
+#define	XXX_P_VMSPACE	ki_vmspace
+
+	buf->rss_rlim = pinfo [0].ki_rssize;
+
+	buf->vsize = (u_int64_t) pinfo [0].ki_size;
+	buf->size = (u_int64_t) pagetok
+		(pinfo [0].ki_tsize + pinfo [0].ki_dsize + pinfo[0].ki_ssize)
+			<< LOG1024;
+	buf->resident = buf->rss = (u_int64_t) pagetok
+		(pinfo [0].ki_rssize) << LOG1024;
+
+#else
+
+#define	XXX_P_VMSPACE	kp_proc.p_vmspace
+
 	if (kvm_read (server->machine.kd,
 		      (unsigned long) pinfo [0].kp_proc.p_limit,
 		      (char *) &plimit, sizeof (plimit)) != sizeof (plimit)) {
@@ -154,11 +171,12 @@
 	
 	buf->resident = buf->rss = (u_int64_t) pagetok
 		(vms->vm_rssize) << LOG1024;
+#endif
 
 	/* Now we get the shared memory. */
 
 	if (kvm_read (server->machine.kd,
-		      (unsigned long) pinfo [0].kp_proc.p_vmspace,
+		      (unsigned long) pinfo [0].XXX_P_VMSPACE,
 		      (char *) &vmspace, sizeof (vmspace)) != sizeof (vmspace)) {
 		glibtop_warn_io_r (server, "kvm_read (vmspace)");
 		return;
