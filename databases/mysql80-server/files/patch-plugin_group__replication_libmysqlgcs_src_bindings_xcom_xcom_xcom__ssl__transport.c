--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c.orig	2019-09-20 08:30:51 UTC
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.c
@@ -329,6 +329,7 @@ error:
   return 1;
 }
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define OPENSSL_ERROR_LENGTH 512
 static int configure_ssl_fips_mode(const uint fips_mode) {
   int rc = -1;
@@ -352,6 +353,7 @@ static int configure_ssl_fips_mode(const uint fips_mod
 EXIT:
   return rc;
 }
+#endif
 
 static int configure_ssl_ca(SSL_CTX *ssl_ctx, const char *ca_file,
                             const char *ca_path) {
@@ -555,10 +557,12 @@ int xcom_init_ssl(const char *server_key_file, const c
   int verify_server = SSL_VERIFY_NONE;
   int verify_client = SSL_VERIFY_NONE;
 
+#ifndef LIBRESSL_VERSION_NUMBER
   if (configure_ssl_fips_mode(ssl_fips_mode) != 1) {
     G_ERROR("Error setting the ssl fips mode");
     goto error;
   }
+#endif
 
   SSL_library_init();
   SSL_load_error_strings();
