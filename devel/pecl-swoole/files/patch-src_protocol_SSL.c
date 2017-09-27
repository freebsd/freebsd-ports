--- src/protocol/SSL.c.orig	2017-09-27 04:04:44 UTC
+++ src/protocol/SSL.c
@@ -98,7 +98,7 @@ static const SSL_METHOD *swSSL_get_metho
 
 void swSSL_init(void)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x10100003L && !defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER >= 0x10100003L
     OPENSSL_init_ssl(OPENSSL_INIT_LOAD_CONFIG, NULL);
 #else
     OPENSSL_config(NULL);
