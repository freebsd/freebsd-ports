
$FreeBSD$

--- sysdeps/freebsd/proctime.c.orig	Thu Feb 15 01:48:46 2001
+++ sysdeps/freebsd/proctime.c	Tue Oct  2 10:58:26 2001
@@ -66,14 +66,17 @@
 {
 	quad_t totusec;
 	u_quad_t u, st, ut, it, tot;
-#if (__FreeBSD_version < 300003)
-        long sec, usec;
-#endif
         struct timeval tv;
 
+#if __FreeBSD_version < 500023
 	st = p->p_sticks;
 	ut = p->p_uticks;
 	it = p->p_iticks;
+#else
+	st = p->p_kse.ke_sticks;
+	ut = p->p_kse.ke_uticks;
+	it = p->p_kse.ke_iticks;
+#endif
 
 	tot = st + ut + it;
 	if (tot == 0) {
@@ -81,12 +84,7 @@
 		tot = 1;
 	}
 
-#if (defined __FreeBSD__) && (__FreeBSD_version >= 300003)
-
-	/* This was changed from a `struct timeval' into a `u_int64_t'
-	 * on FreeBSD 3.0 and renamed p_rtime -> p_runtime.
-	 */
-
+#if (defined __FreeBSD__)
 	totusec = (u_quad_t) p->p_runtime;
 #else
 	sec = p->p_rtime.tv_sec;
@@ -157,10 +155,10 @@
 	if ((pinfo == NULL) || (count != 1))
 		glibtop_error_io_r (server, "kvm_getprocs (%d)", pid);
 
-#if (defined __FreeBSD__) && (__FreeBSD_version >= 300003)
-	buf->rtime = pinfo [0].kp_proc.p_runtime;
+#if (defined __FreeBSD__) && (__FreeBSD_version >= 500013)
+	buf->rtime = pinfo [0].ki_runtime;
 #else
-	buf->rtime = tv2sec (pinfo [0].kp_proc.p_rtime);
+	buf->rtime = pinfo [0].kp_proc.p_runtime;
 #endif
 
 	buf->frequency = 1000000;
@@ -192,6 +190,21 @@
 
 	buf->flags |= _glibtop_sysdeps_proc_time_user;
 #else
+#if __FreeBSD_version >= 500013
+#if __FreeBSD_version >= 500016
+	if ((pinfo [0].ki_flag & PS_INMEM)) {
+#else
+	if ((pinfo [0].ki_flag & P_INMEM)) {
+#endif
+	    buf->utime = pinfo [0].ki_runtime;
+	    buf->stime = 0; /* XXX */
+	    buf->cutime = tv2sec (pinfo [0].ki_childtime);
+	    buf->cstime = 0; /* XXX */
+	    buf->start_time = tv2sec (pinfo [0].ki_start);
+	    buf->flags = _glibtop_sysdeps_proc_time_user;
+	}
+
+#else
 	glibtop_suid_enter (server);
 
 	if ((pinfo [0].kp_proc.p_flag & P_INMEM) &&
@@ -222,6 +235,7 @@
 
 			buf->flags = _glibtop_sysdeps_proc_time_user;
 		}
+#endif
 
 	glibtop_suid_leave (server);
 #endif
