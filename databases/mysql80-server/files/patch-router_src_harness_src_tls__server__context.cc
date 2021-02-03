--- router/src/http/src/tls_server_context.cc.orig	2019-09-20 08:30:51 UTC
+++ router/src/http/src/tls_server_context.cc
@@ -166,7 +166,8 @@ void TlsServerContext::init_tmp_dh(const std::string &
     }
 
   } else {
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) && \
+    !defined(LIBRESSL_VERSION_NUMBER)
     dh2048.reset(DH_get_2048_256());
 #else
     /*
