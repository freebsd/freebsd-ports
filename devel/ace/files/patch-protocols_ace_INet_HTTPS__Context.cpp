--- protocols/ace/INet/HTTPS_Context.cpp.orig	2014-12-29 10:41:20 UTC
+++ protocols/ace/INet/HTTPS_Context.cpp
@@ -18,7 +18,11 @@ namespace ACE
   namespace HTTPS
   {
 
+#ifndef OPENSSL_NO_SSL3
     int Context::ssl_mode_ =  ACE_SSL_Context::SSLv3;
+#else
+    int Context::ssl_mode_ =  ACE_SSL_Context::SSLv23;
+#endif
     bool Context::ssl_strict_ = false;
     bool Context::ssl_once_ = true;
     int Context::ssl_depth_ = 0;
