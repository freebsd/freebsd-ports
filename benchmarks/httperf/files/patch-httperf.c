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
@@ -807,8 +807,7 @@ main (int argc, char **argv)
       SSL_load_error_strings ();
       SSLeay_add_ssl_algorithms ();
 
-      /* for some strange reason, SSLv23_client_method () doesn't work here */
-      ssl_ctx = SSL_CTX_new (SSLv3_client_method ());
+      ssl_ctx = SSL_CTX_new (SSLv23_client_method ());
       if (!ssl_ctx)
 	{
 	  ERR_print_errors_fp (stderr);
