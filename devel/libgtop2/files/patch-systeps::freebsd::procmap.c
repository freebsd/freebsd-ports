--- sysdeps/freebsd/procmap.c	Wed Feb 23 17:20:45 2005
+++ sysdeps/freebsd/procmap.c.orig	Sat Mar 19 02:46:57 2005
@@ -129,7 +129,7 @@
 	/* Get the process data */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
 	if ((pinfo == NULL) || (count < 1)) {
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
 		return NULL;
 	}
 
