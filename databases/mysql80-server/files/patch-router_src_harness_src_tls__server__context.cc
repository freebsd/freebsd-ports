--- router/src/harness/src/tls_server_context.cc.orig	2021-12-17 16:07:27 UTC
+++ router/src/harness/src/tls_server_context.cc
@@ -169,7 +169,8 @@ stdx::expected<void, std::error_code> TlsServerContext
     }
 
   } else {
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) && \
+    !defined(LIBRESSL_VERSION_NUMBER)
     dh2048.reset(DH_get_2048_256());
 #else
     /*
