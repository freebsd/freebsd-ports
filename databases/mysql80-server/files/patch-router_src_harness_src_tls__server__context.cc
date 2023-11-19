--- router/src/harness/src/tls_server_context.cc.orig	2023-11-18 19:39:18.923205000 +0100
+++ router/src/harness/src/tls_server_context.cc	2023-11-18 19:42:53.690094000 +0100
@@ -474,7 +474,8 @@ int TlsServerContext::security_level() const {
 }
 
 int TlsServerContext::security_level() const {
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0)
+#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 0) \
+  && !defined(LIBRESSL_VERSION_NUMBER)
   int sec_level = SSL_CTX_get_security_level(ssl_ctx_.get());
 
   assert(sec_level <= kMaxSecurityLevel);
