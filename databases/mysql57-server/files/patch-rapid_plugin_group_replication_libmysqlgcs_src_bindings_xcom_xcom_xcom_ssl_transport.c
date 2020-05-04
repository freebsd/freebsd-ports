--- rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c.orig	2020-03-23 17:35:17 UTC
+++ rapid/plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c
@@ -529,7 +529,7 @@ int xcom_init_ssl(const char *server_key_file, const c
     break e.g. ODBC clients (if the client also uses SSL).
   */
 
-#if defined(HAVE_STATIC_OPENSSL)
+#if defined(HAVE_STATIC_OPENSSL) && !defined(LIBRESSL_VERSION_NUMBER)
   OPENSSL_init_crypto(OPENSSL_INIT_NO_ATEXIT, NULL);
 #else
   SSL_library_init();
