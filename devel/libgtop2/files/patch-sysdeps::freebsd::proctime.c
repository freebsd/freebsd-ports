--- sysdeps/freebsd/proctime.c.orig	Wed Mar 10 21:23:52 2004
+++ sysdeps/freebsd/proctime.c	Thu Mar 11 15:47:35 2004
@@ -59,6 +59,7 @@
 
 #ifndef __FreeBSD__
 
+#ifndef __FreeBSD__
 static void
 calcru(p, up, sp, ip)
      struct proc *p;
@@ -81,19 +82,10 @@
 		tot = 1;
 	}
 
-#if (defined __FreeBSD__) && (__FreeBSD_version >= 300003)
-
-	/* This was changed from a `struct timeval' into a `guint64'
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
@@ -116,6 +108,7 @@
 		ip->tv_usec = it % 1000000;
 	}
 }
+#endif
 
 #endif /* !__FreeBSD__ */
 
@@ -133,9 +126,6 @@
 #endif
 	struct pstats pstats;
 	int count;
-
-	char filename [BUFSIZ];
-	struct stat statb;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_PROC_TIME), 0);
 	
