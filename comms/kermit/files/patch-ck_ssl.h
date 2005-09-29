--- ck_ssl.h.orig	Sun Mar 14 18:08:23 2004
+++ ck_ssl.h	Thu Sep 29 20:31:23 2005
@@ -39,6 +39,7 @@
  * definitions there is no reason to have it included by openssl/evp.h
  */
 #define OPENSSL_NO_MDC2
+#undef EM
 #include <openssl/des.h>
 #include <openssl/ssl.h>
 #include <openssl/x509v3.h>
