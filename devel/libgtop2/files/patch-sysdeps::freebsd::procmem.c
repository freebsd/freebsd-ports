--- sysdeps/freebsd/procmem.c.orig	Mon Jul 19 02:07:03 2004
+++ sysdeps/freebsd/procmem.c	Tue Jul 20 22:03:29 2004
@@ -125,7 +125,7 @@
 #else
 	struct vm_object object;
 #endif
-	struct plimit plimit;
+	struct rlimit rlimit;
 	int count;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_MEM), 0);
@@ -160,15 +160,12 @@
 
 #define        PROC_VMSPACE   kp_proc.p_vmspace
 
-	if (kvm_read (server->machine.kd,
-		      (unsigned long) pinfo [0].PROC_VMSPACE,
-		      (char *) &plimit, sizeof (plimit)) != sizeof (plimit)) {
-		glibtop_warn_io_r (server, "kvm_read (plimit)");
+        if (getrlimit (RLIMIT_RSS, &rlimit) < 0) {
+	        glibtop_warn_io_r (server, "getrlimit");
 		return;
 	}
 
-	buf->rss_rlim = (guint64)
-		(plimit.pl_rlimit [RLIMIT_RSS].rlim_cur);
+	buf->rss_rlim = (u_int64_t) (rlimit.rlim_cur);
 
 	vms = &pinfo [0].kp_eproc.e_vm;
 
