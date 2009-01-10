--- sysdeps/freebsd/nosuid.c.orig	2008-09-29 17:28:31.000000000 -0400
+++ sysdeps/freebsd/nosuid.c	2008-09-29 17:28:39.000000000 -0400
@@ -21,16 +21,8 @@
 
 #include <config.h>
 #include <glibtop.h>
-#include <glibtop/open.h>
 #include <glibtop/close.h>
 
 void
-glibtop_open_s (glibtop *server,
-		const char *program_name,
-		const unsigned long features,
-		const unsigned flags)
-{ }
-
-void
 glibtop_close_s (glibtop *server)
 { }
