--- sysdeps/freebsd/shm_limits.c.orig	2008-02-14 12:26:46.000000000 -0500
+++ sysdeps/freebsd/shm_limits.c	2008-02-14 12:26:29.000000000 -0500
@@ -25,6 +25,7 @@
 #include <glibtop/shm_limits.h>
 
 #include <sys/types.h>
+#include <sys/param.h>
 #include <sys/sysctl.h>
 
 static unsigned long _glibtop_sysdeps_shm_limits =
@@ -46,7 +47,11 @@ void
 glibtop_get_shm_limits_s (glibtop *server, glibtop_shm_limits *buf)
 {
 	size_t len;
+#if __FreeBSD_version < 800020
 	int shmmax, shmmin, shmmni, shmseg, shmall;
+#else
+	unsigned long shmmax, shmmin, shmmni, shmseg, shmall;
+#endif
 
 	glibtop_init_s (&server, GLIBTOP_SYSDEPS_SHM_LIMITS, 0);
 
