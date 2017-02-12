--- modules/mod_tls.c.orig	2017-01-16 01:13:01 UTC
+++ modules/mod_tls.c
@@ -609,7 +609,7 @@ static void tls_diags_cb(const SSL *ssl,
         break;
 #endif
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
       case TLS_ST_OK:
 #else
       case SSL_ST_OK:
@@ -633,7 +633,7 @@ static void tls_diags_cb(const SSL *ssl,
 
     ssl_state = SSL_get_state(ssl);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     if (ssl_state == TLS_ST_SR_CLNT_HELLO) {
 #else
     if (ssl_state == SSL3_ST_SR_CLNT_HELLO_A ||
