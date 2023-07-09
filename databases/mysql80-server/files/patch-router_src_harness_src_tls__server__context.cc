--- router/src/harness/src/tls_server_context.cc.orig	2023-06-29 15:05:27.686865000 +0200
+++ router/src/harness/src/tls_server_context.cc	2023-06-29 15:31:25.869049000 +0200
@@ -275,7 +275,9 @@ stdx::expected<void, std::error_code> set_auto_dh_para
 #if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(3, 0, 0)
   SSL_CTX_set_dh_auto(ssl_ctx, 1);
 #else
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) \
+  && !defined(LIBRESSL_VERSION_NUMBER)
+
   int sec_level = SSL_CTX_get_security_level(ssl_ctx);
 
   assert(sec_level <= kMaxSecurityLevel);
