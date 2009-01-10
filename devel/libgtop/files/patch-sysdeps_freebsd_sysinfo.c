--- sysdeps/freebsd/sysinfo.c.orig	2008-05-23 18:13:23.000000000 -0400
+++ sysdeps/freebsd/sysinfo.c	2008-09-29 14:35:25.000000000 -0400
@@ -45,8 +45,8 @@ init_sysinfo (glibtop *server)
 
 	glibtop_init_s (&server, GLIBTOP_SYSDEPS_CPU, 0);
 
-	len = sizeof (ncpus);
-	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
+	ncpus = server->ncpu + 1;
+
 	len = 0;
 	sysctlbyname ("hw.model", NULL, &len, NULL, 0);
 	model = g_malloc (len);
