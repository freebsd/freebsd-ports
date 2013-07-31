--- sysdeps/freebsd/open.c.orig	2011-07-24 15:13:56.000000000 -0400
+++ sysdeps/freebsd/open.c	2011-12-28 16:26:48.000000000 -0500
@@ -42,11 +42,5 @@ glibtop_open_s (glibtop *server, const c
 	sysctlbyname ("hw.ncpu", &ncpus, &len, NULL, 0);
 	server->real_ncpu = ncpus - 1;
 	server->ncpu = MIN(GLIBTOP_NCPU - 1, server->real_ncpu);
-
-#if defined(__FreeBSD_kernel__)
-	server->os_version_code = __FreeBSD_kernel_version;
-#else
 	server->os_version_code = __FreeBSD_version;
-#endif
-
 }
