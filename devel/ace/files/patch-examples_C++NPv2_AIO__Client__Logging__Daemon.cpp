--- examples/C++NPv2/AIO_Client_Logging_Daemon.cpp.orig	2014-12-29 10:41:20 UTC
+++ examples/C++NPv2/AIO_Client_Logging_Daemon.cpp
@@ -237,7 +237,7 @@ int AIO_CLD_Connector::validate_connecti
 
   if (ssl_ctx_ == 0) {
     OpenSSL_add_ssl_algorithms ();
-    ssl_ctx_ = SSL_CTX_new (SSLv3_client_method ());
+    ssl_ctx_ = SSL_CTX_new (SSLv23_client_method ());
     if (ssl_ctx_ == 0) return -1;
 
     if (SSL_CTX_use_certificate_file (ssl_ctx_,
