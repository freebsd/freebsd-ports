--- sysdeps/freebsd/proctime.c	Wed Feb 23 17:20:45 2005
+++ sysdeps/freebsd/proctime.c.orig	Sat Mar 19 02:38:31 2005
@@ -146,8 +146,10 @@
 
 	/* Get the process information */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
-	if ((pinfo == NULL) || (count != 1))
-		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
+	if ((pinfo == NULL) || (count != 1)) {
+		glibtop_warn_io_r (server, "kvm_getprocs (%d)", pid);
+		return;
+	}
 
 #if defined(__FreeBSD__) && (__FreeBSD_version >= 500013)
 	buf->rtime = pinfo [0].ki_runtime;
