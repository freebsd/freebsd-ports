--- httperf.c.orig	Wed Nov  1 05:20:00 2000
+++ httperf.c	Wed Nov 13 06:19:41 2002
@@ -68,6 +68,10 @@
 #include <conn.h>
 #include <timer.h>
 
+#ifdef __FreeBSD__
+#include <machine/floatingpoint.h>
+#endif
+
 #ifdef HAVE_SSL
 #  include <openssl/rand.h>
 #endif
