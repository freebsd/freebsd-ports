--- sysdeps/freebsd/swap.c.orig	Mon Aug 26 20:18:07 2002
+++ sysdeps/freebsd/swap.c	Mon Aug 26 20:19:18 2002
@@ -369,8 +369,8 @@
 
 	buf->flags = _glibtop_sysdeps_swap;
 
-	buf->used = kvmsw[nswdev].ksw_used;
-	buf->total = kvmsw[nswdev].ksw_total;
+	buf->used = kvmsw[nswdev].ksw_used * getpagesize();
+	buf->total = kvmsw[nswdev].ksw_total * getpagesize();
 
 	buf->free = buf->total - buf->used;

