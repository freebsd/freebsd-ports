--- src/gnutls.c.orig	2010-02-20 21:56:01.000000000 +0200
+++ src/gnutls.c	2010-02-20 21:56:15.000000000 +0200
@@ -181,7 +181,7 @@
 };
 
 bool
-ssl_connect (int fd)
+ssl_connect_wget (int fd)
 {
   static const int cert_type_priority[] = {
     GNUTLS_CRT_X509, GNUTLS_CRT_OPENPGP, 0
