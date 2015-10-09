--- examples/C++NPv2/AC_Client_Logging_Daemon.cpp.orig	2014-12-29 11:41:20.228461000 +0100
+++ examples/C++NPv2/AC_Client_Logging_Daemon.cpp	2015-10-04 13:15:10.508003133 +0200
@@ -320,7 +320,7 @@ int AC_CLD_Acceptor::handle_close (ACE_H
 int AC_CLD_Connector::open (ACE_Reactor *r, int flags) {
   if (PARENT::open (r, flags) != 0) return -1;
   OpenSSL_add_ssl_algorithms ();
-  ssl_ctx_ = SSL_CTX_new (SSLv3_client_method ());
+  ssl_ctx_ = SSL_CTX_new (SSLv23_client_method ());
   if (ssl_ctx_ == 0) return -1;
 
   if (SSL_CTX_use_certificate_file (ssl_ctx_,
