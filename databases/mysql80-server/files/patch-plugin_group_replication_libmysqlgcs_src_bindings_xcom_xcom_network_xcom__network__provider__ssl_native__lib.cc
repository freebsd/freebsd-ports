--- plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/network/xcom_network_provider_ssl_native_lib.cc.orig	2022-02-20 15:21:13.279471000 -0800
+++ plugin/group_replication/libmysqlgcs/src/bindings/xcom/xcom/network/xcom_network_provider_ssl_native_lib.cc	2022-02-20 15:22:02.451078000 -0800
@@ -318,6 +318,7 @@
 
 #define OPENSSL_ERROR_LENGTH 512
 static int configure_ssl_fips_mode(const int fips_mode) {
+#ifndef LIBRESSL_VERSION_NUMBER
   int rc = -1;
   int fips_mode_old = -1;
   char err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
@@ -338,6 +339,9 @@
   }
 EXIT:
   return rc;
+# else
+  return -1;
+# endif
 }
 
 static int configure_ssl_ca(SSL_CTX *ssl_ctx, const char *ca_file,
