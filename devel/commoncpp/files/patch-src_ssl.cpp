--- src/ssl.cpp.orig	2010-11-01 00:42:51 UTC
+++ src/ssl.cpp
@@ -386,7 +386,7 @@ bool SSLStream::getSession(void)
     if(so == INVALID_SOCKET)
         return false;
 
-    ctx = SSL_CTX_new(SSLv3_client_method());
+    ctx = SSL_CTX_new(SSLv23_client_method());
     if(!ctx) {
         SSL_CTX_free(ctx);
         return false;
