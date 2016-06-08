--- examples/C++NPv2/TPC_Logging_Server.cpp.orig	2014-12-29 10:41:20 UTC
+++ examples/C++NPv2/TPC_Logging_Server.cpp
@@ -53,7 +53,7 @@ int TPC_Logging_Acceptor::open
                     use_select, reuse_addr) != 0)
     return -1;
   OpenSSL_add_ssl_algorithms ();
-  ssl_ctx_ = SSL_CTX_new (SSLv3_server_method ());
+  ssl_ctx_ = SSL_CTX_new (SSLv23_server_method ());
   if (ssl_ctx_ == 0) return -1;
 
   if (SSL_CTX_use_certificate_file (ssl_ctx_,
