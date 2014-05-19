--- ./src/tcp.c.orig	2014-04-22 07:33:25.000000000 -0600
+++ ./src/tcp.c	2014-05-17 10:49:10.247327329 -0600
@@ -62,7 +62,10 @@
 	static int called_gnutls_global_init = 0;
 #endif
 
-
+#include <netdb.h>
+#ifndef SOL_TCP
+#define SOL_TCP (getprotobyname("TCP")->p_proto)
+#endif
 
 #ifdef ENABLE_TLS
 /* forward definitions */
