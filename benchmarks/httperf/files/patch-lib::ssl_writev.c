--- lib/ssl_writev.c.orig	Thu Oct 12 09:09:47 2000
+++ lib/ssl_writev.c	Wed Nov 13 06:22:01 2002
@@ -31,7 +31,10 @@
 
 #ifdef HAVE_OPENSSL_SSL_H
 
+#ifdef HAVE_ALLOCA_H
 #include <alloca.h>
+#endif
+
 #include <string.h>
 
 #include <sys/types.h>
