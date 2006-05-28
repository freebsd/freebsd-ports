--- sysdeps/freebsd/prockernel.c	Mon Jul 19 05:33:56 2004
+++ sysdeps/freebsd/prockernel.c.orig	Sat Mar 19 02:39:47 2005
@@ -115,8 +115,10 @@
 
 	/* Get the process information */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
-	if ((pinfo == NULL) || (count != 1))
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
+	if ((pinfo == NULL) || (count != 1)) {
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
+		return;
+	}
 
 #if defined(__FreeBSD__) && (__FreeBSD_version >= 500013)
 
