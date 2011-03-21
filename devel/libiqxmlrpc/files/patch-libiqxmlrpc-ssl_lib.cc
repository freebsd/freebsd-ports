--- libiqxmlrpc/ssl_lib.cc.orig	2011-03-21 23:16:31.000000000 +0600
+++ libiqxmlrpc/ssl_lib.cc	2011-03-21 23:16:46.000000000 +0600
@@ -55,7 +55,7 @@
 {
   init_library();
 
-  SSL_METHOD* meth = client ? SSLv23_method() : SSLv23_server_method();
+  const SSL_METHOD* meth = client ? SSLv23_method() : SSLv23_server_method();
   ctx = SSL_CTX_new( meth );
 
   if(
@@ -71,7 +71,7 @@
 {
   init_library();
 
-  SSL_METHOD *meth = SSLv23_client_method();
+  const SSL_METHOD *meth = SSLv23_client_method();
   ctx = SSL_CTX_new( meth );
 }
 
