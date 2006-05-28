--- sysdeps/freebsd/proctime.c.orig	Wed Feb 23 03:20:45 2005
+++ sysdeps/freebsd/proctime.c	Tue Aug  2 12:49:38 2005
@@ -146,8 +146,10 @@ glibtop_get_proc_time_p (glibtop *server
 
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
@@ -193,9 +195,13 @@ glibtop_get_proc_time_p (glibtop *server
        if ((pinfo [0].ki_flag & P_INMEM)) {
 #endif
            buf->utime = pinfo [0].ki_runtime;
-           buf->stime = 0; /* XXX */
+		   buf->stime = tv2sec (pinfo [0].ki_rusage.ru_stime);
            buf->cutime = tv2sec (pinfo [0].ki_childtime);
-           buf->cstime = 0; /* XXX */
+#if __FreeBSD_version >= 600000
+		   buf->cstime = tv2sec (pinfo [0].ki_rusage_ch.ru_stime);
+#else
+		   buf->cstime = 0;
+#endif
            buf->start_time = tv2sec (pinfo [0].ki_start);
            buf->flags = _glibtop_sysdeps_proc_time_user;
        }
