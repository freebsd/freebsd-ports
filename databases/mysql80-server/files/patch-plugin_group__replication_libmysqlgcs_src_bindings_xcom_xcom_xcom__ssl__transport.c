--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.cc.orig	2019-09-20 08:30:51 UTC
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/xcom_ssl_transport.cc
@@ -175,7 +175,7 @@ SSL_CTX *client_ctx = NULL;
 static long process_tls_version(const char *tls_version) {
   const char *separator = ", ";
   char *token = NULL;
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   const char *tls_version_name_list[] = {"TLSv1", "TLSv1.1", "TLSv1.2",
                                          "TLSv1.3"};
 #else
@@ -184,7 +184,7 @@ static long process_tls_version(const char *tls_versio
 #define TLS_VERSIONS_COUNTS \
   (sizeof(tls_version_name_list) / sizeof(*tls_version_name_list))
   unsigned int tls_versions_count = TLS_VERSIONS_COUNTS;
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   const long tls_ctx_list[TLS_VERSIONS_COUNTS] = {
       SSL_OP_NO_TLSv1, SSL_OP_NO_TLSv1_1, SSL_OP_NO_TLSv1_2, SSL_OP_NO_TLSv1_3};
   const char *ctx_flag_default = "TLSv1,TLSv1.1,TLSv1.2,TLSv1.3";
@@ -240,7 +240,7 @@ static int configure_ssl_algorithms(
   long ssl_ctx_options = SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3;
   char cipher_list[SSL_CIPHER_LIST_SIZE] = {0};
   long ssl_ctx_flags = -1;
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   int tlsv1_3_enabled = 0;
 #endif /* HAVE_TLSv13 */
 
@@ -253,7 +253,7 @@ static int configure_ssl_algorithms(
     goto error;
   }
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   ssl_ctx_options = (ssl_ctx_options | ssl_ctx_flags) &
                     (SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3 | SSL_OP_NO_TLSv1 |
                      SSL_OP_NO_TLSv1_1 | SSL_OP_NO_TLSv1_2 | SSL_OP_NO_TLSv1_3);
@@ -265,7 +265,7 @@ static int configure_ssl_algorithms(
 
   SSL_CTX_set_options(ssl_ctx, ssl_ctx_options);
 
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   tlsv1_3_enabled = ((ssl_ctx_options & SSL_OP_NO_TLSv1_3) == 0);
   if (tlsv1_3_enabled) {
     /* Set OpenSSL TLS v1.3 ciphersuites.
@@ -325,6 +325,7 @@ error:
   return 1;
 }
 
+#ifndef LIBRESSL_VERSION_NUMBER
 #define OPENSSL_ERROR_LENGTH 512
 static int configure_ssl_fips_mode(const uint fips_mode) {
   int rc = -1;
@@ -348,6 +349,7 @@ static int configure_ssl_fips_mode(const uint fips_mod
 EXIT:
   return rc;
 }
+#endif
 
 static int configure_ssl_ca(SSL_CTX *ssl_ctx, const char *ca_file,
                             const char *ca_path) {
@@ -544,10 +546,12 @@ int xcom_init_ssl(const char *server_key_file, const c
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
@@ -563,7 +567,7 @@ int xcom_init_ssl(const char *server_key_file, const c
   }
 
   G_DEBUG("Configuring SSL for the server")
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   server_ctx = SSL_CTX_new(TLS_server_method());
 #else
   server_ctx = SSL_CTX_new(SSLv23_server_method());
@@ -582,7 +586,7 @@ int xcom_init_ssl(const char *server_key_file, const c
   SSL_CTX_set_verify(server_ctx, verify_server, NULL);
 
   G_DEBUG("Configuring SSL for the client")
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
   client_ctx = SSL_CTX_new(TLS_client_method());
 #else
   client_ctx = SSL_CTX_new(SSLv23_client_method());
