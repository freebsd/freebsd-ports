--- src/httperf.c.orig	2007-12-11 10:48:02.000000000 +0000
+++ src/httperf.c	2007-12-11 10:48:48.000000000 +0000
@@ -78,6 +78,10 @@
 #include <conn.h>
 #include <timer.h>
 
+#ifdef __FreeBSD__
+#include <machine/floatingpoint.h>
+#endif
+
 #ifdef HAVE_SSL
 #  include <openssl/rand.h>
 #endif
