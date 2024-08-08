--- router/src/harness/src/tls_server_context.cc.orig	2024-07-12 19:15:25 UTC
+++ router/src/harness/src/tls_server_context.cc
@@ -475,7 +475,8 @@ int TlsServerContext::security_level() const {
 }
 
 int TlsServerContext::security_level() const {
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) \
+  && !defined(LIBRESSL_VERSION_NUMBER)
   int sec_level = SSL_CTX_get_security_level(ssl_ctx_.get());
 
   assert(sec_level <= kMaxSecurityLevel);
