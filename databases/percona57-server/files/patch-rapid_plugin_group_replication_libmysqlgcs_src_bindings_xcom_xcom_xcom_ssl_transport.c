--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c.orig	2020-03-23 17:35:17 UTC
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c
@@ -230,7 +230,7 @@ static int configure_ssl_algorithms(SSL_CTX* ssl_ctx, 
                                     const char* tls_version)
 {
   DH *dh= NULL;
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /* We support TLS up to 1.2, so explicitly disable TLS 1.3. */
   long ssl_ctx_options= SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1_3;
 #else
@@ -255,14 +255,14 @@ static int configure_ssl_algorithms(SSL_CTX* ssl_ctx, 
                     SSL_OP_NO_TLSv1 |
                     SSL_OP_NO_TLSv1_1
                     | SSL_OP_NO_TLSv1_2
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
                     | SSL_OP_NO_TLSv1_3
 #endif /* HAVE_TLSv13 */
                    );
 
   SSL_CTX_set_options(ssl_ctx, ssl_ctx_options);
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   /* We do not support TLS 1.3.
      Setting empty TLS 1.3 ciphersuites disables them. */
   if (SSL_CTX_set_ciphersuites(ssl_ctx, "") == 0)
@@ -527,7 +527,7 @@ int xcom_init_ssl(const char *server_key_file, const c
     break e.g. ODBC clients (if the client also uses SSL).
   */
 
-#if defined(HAVE_STATIC_OPENSSL)
+#if defined(HAVE_STATIC_OPENSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   OPENSSL_init_crypto(OPENSSL_INIT_NO_ATEXIT, NULL);
 #else
   SSL_library_init();
