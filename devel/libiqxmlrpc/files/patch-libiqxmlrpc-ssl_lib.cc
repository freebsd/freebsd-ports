--- libiqxmlrpc/ssl_lib.cc.orig	2010-08-14 02:12:36.000000000 +0700
+++ libiqxmlrpc/ssl_lib.cc	2011-03-22 00:13:33.000000000 +0600
@@ -55,8 +55,7 @@
 {
   init_library();
 
-  SSL_METHOD* meth = client ? SSLv23_method() : SSLv23_server_method();
-  ctx = SSL_CTX_new( meth );
+  ctx = SSL_CTX_new( client ? SSLv23_method() : SSLv23_server_method() );
 
   if(
     !SSL_CTX_use_certificate_file( ctx, cert_path.c_str(), SSL_FILETYPE_PEM ) ||
@@ -71,8 +70,7 @@
 {
   init_library();
 
-  SSL_METHOD *meth = SSLv23_client_method();
-  ctx = SSL_CTX_new( meth );
+  ctx = SSL_CTX_new( SSLv23_client_method() );
 }
 
 
