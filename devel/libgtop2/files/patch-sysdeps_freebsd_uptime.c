--- sysdeps/freebsd/uptime.c.orig	Thu Mar 11 15:59:16 2004
+++ sysdeps/freebsd/uptime.c	Thu Mar 11 15:59:38 2004
@@ -68,9 +68,8 @@
 		buf->flags = _glibtop_sysdeps_uptime;
 	}
 #else
-	buf->flags = _glibtop_sysdeps_uptime;
-
 	glibtop_cpu cpu;
+	buf->flags = _glibtop_sysdeps_uptime;
 
 	glibtop_init_p (server, (1L << GLIBTOP_SYSDEPS_UPTIME), 0);
 	
