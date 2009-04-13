--- sysdeps/freebsd/cpu.c.orig	2009-04-12 01:45:28.000000000 -0400
+++ sysdeps/freebsd/cpu.c	2009-04-12 01:45:29.000000000 -0400
@@ -54,6 +54,7 @@ void
 glibtop_get_cpu_s (glibtop *server, glibtop_cpu *buf)
 {
 	long cpts [CPUSTATES];
+	long *cp_times = NULL;
 	struct clockinfo ci;
 	size_t length;
 	int ncpu, i;
@@ -75,6 +76,16 @@ glibtop_get_cpu_s (glibtop *server, glib
 		return;
 	}
 
+	length = 0;
+	if (sysctlbyname ("kern.cp_times", NULL, &length, NULL, 0) == 0) {
+		cp_times = g_malloc (length);
+		length = sizeof(long) * CPUSTATES * (length / (sizeof(long) * CPUSTATES));
+		if (sysctlbyname ("kern.cp_times", cp_times, &length, NULL, 0)) {
+			g_free (cp_times);
+			cp_times = NULL;
+		}
+	}
+
 	/* set user time */
 	buf->user = cpts [CP_USER];
 	/* set nice time */
@@ -89,22 +100,32 @@ glibtop_get_cpu_s (glibtop *server, glib
 	/* set frequency */
 	buf->frequency = (ci.stathz ? ci.stathz : ci.hz);
 	/* set total */
-	buf->total = cpts [CP_USER] + cpts [CP_NICE]
+	buf->total = cpts [CP_USER] + cpts [CP_NICE] \
 		+ cpts [CP_SYS] + cpts [CP_IDLE] + cpts [CP_INTR];
 
 	ncpu = server->ncpu + 1;
 
 	for (i = 0; i < ncpu; i++) {
-		buf->xcpu_user[i] = cpts [CP_USER] / ncpu;
-		buf->xcpu_nice[i] = cpts [CP_NICE] / ncpu;
-		buf->xcpu_sys[i] = cpts [CP_SYS] / ncpu;
-		buf->xcpu_idle[i] = cpts [CP_IDLE] / ncpu;
-		buf->xcpu_irq[i] = cpts [CP_INTR] / ncpu;
+		if (cp_times) {
+			buf->xcpu_user[i] = cp_times[i * CPUSTATES + CP_USER];
+			buf->xcpu_nice[i] = cp_times[i * CPUSTATES + CP_NICE];
+			buf->xcpu_sys[i] = cp_times[i * CPUSTATES + CP_SYS];
+			buf->xcpu_idle[i] = cp_times[i * CPUSTATES + CP_IDLE];
+			buf->xcpu_irq[i] = cp_times[i * CPUSTATES + CP_INTR];
+		} else {
+			buf->xcpu_user[i] = cpts [CP_USER] / ncpu;
+			buf->xcpu_nice[i] = cpts [CP_NICE] / ncpu;
+			buf->xcpu_sys[i] = cpts [CP_SYS] / ncpu;
+			buf->xcpu_idle[i] = cpts [CP_IDLE] / ncpu;
+			buf->xcpu_irq[i] = cpts [CP_INTR] / ncpu;
+		}
 		buf->xcpu_total[i] = buf->xcpu_user[i] + buf->xcpu_nice[i] \
 				     + buf->xcpu_sys[i] + buf->xcpu_idle[i] \
 				     + buf->xcpu_irq[i];
 	}
 
+	g_free (cp_times);
+
 	/* Set the flags last. */
 	buf->flags = _glibtop_sysdeps_cpu;
 
