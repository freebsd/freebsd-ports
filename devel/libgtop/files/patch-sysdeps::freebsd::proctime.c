--- sysdeps/freebsd/proctime.c.orig	Mon Nov 26 17:37:59 2001
+++ sysdeps/freebsd/proctime.c	Wed Oct  2 21:26:35 2002
@@ -57,6 +57,7 @@
  * system, and interrupt time usage.
  */
 
+#ifndef __FreeBSD__
 static void
 calcru(p, up, sp, ip)
      struct proc *p;
@@ -66,9 +67,6 @@
 {
 	quad_t totusec;
 	u_quad_t u, st, ut, it, tot;
-#if (__FreeBSD_version < 300003)
-        long sec, usec;
-#endif
         struct timeval tv;
 
 	st = p->p_sticks;
@@ -81,19 +79,10 @@
 		tot = 1;
 	}
 
-#if (defined __FreeBSD__) && (__FreeBSD_version >= 300003)
-
-	/* This was changed from a `struct timeval' into a `u_int64_t'
-	 * on FreeBSD 3.0 and renamed p_rtime -> p_runtime.
-	 */
-
-	totusec = (u_quad_t) p->p_runtime;
-#else
 	sec = p->p_rtime.tv_sec;
 	usec = p->p_rtime.tv_usec;
 
 	totusec = (quad_t)sec * 1000000 + usec;
-#endif
 
 	if (totusec < 0) {
 		/* XXX no %qd in kernel.  Truncate. */
@@ -116,6 +105,7 @@
 		ip->tv_usec = it % 1000000;
 	}
 }
+#endif
 
 /* Provides detailed information about a process. */
 
@@ -142,25 +132,25 @@
 	/* It does not work for the swapper task. */
 	if (pid == 0) return;
 	
-#if !(defined(__NetBSD__) && (__NetBSD_Version__ >= 104000000))
+#if (defined(__NetBSD__) && (__NetBSD_Version__ >= 104000000))
 	if (server->sysdeps.proc_time == 0)
 		return;
+#endif
 
 #ifndef __bsdi__
 	sprintf (filename, "/proc/%d/mem", (int) pid);
 	if (stat (filename, &statb)) return;
 #endif
-#endif
 
 	/* Get the process information */
 	pinfo = kvm_getprocs (server->machine.kd, KERN_PROC_PID, pid, &count);
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
@@ -192,6 +182,21 @@
 
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
@@ -199,29 +204,16 @@
 		       (unsigned long) &u_addr->u_stats,
 		       (char *) &pstats, sizeof (pstats)) == sizeof (pstats))
 		{
-			/* This is taken form the kernel source code of
-			 * FreeBSD 2.2.6. */
-
-			/* Well, we just do the same getrusage () does ... */
-
-			register struct rusage *rup;
-
-			glibtop_suid_leave (server);
-
-			rup = &pstats.p_ru;
-			calcru(&(pinfo [0]).kp_proc,
-			       &rup->ru_utime, &rup->ru_stime, NULL);
-
-			buf->utime = tv2sec (pstats.p_ru.ru_utime);
-			buf->stime = tv2sec (pstats.p_ru.ru_stime);
-			
-			buf->cutime = tv2sec (pstats.p_cru.ru_utime);
-			buf->cstime = tv2sec (pstats.p_cru.ru_stime);
-
-			buf->start_time = tv2sec (pstats.p_start);
+			buf->utime = tv2sec (pinfo[0].kp_eproc.e_stats.p_ru.ru_utime);
+			buf->stime = tv2sec (pinfo[0].kp_eproc.e_stats.p_ru.ru_stime);
+			buf->cutime = tv2sec (pinfo[0].kp_eproc.e_stats.p_cru.ru_utime);
+			buf->cstime = tv2sec (pinfo[0].kp_eproc.e_stats.p_cru.ru_stime);
+			buf->start_time = tv2sec (pinfo[0].kp_eproc.e_stats.p_start);
 
 			buf->flags = _glibtop_sysdeps_proc_time_user;
+			glibtop_suid_leave (server);
 		}
+#endif
 
 	glibtop_suid_leave (server);
 #endif
