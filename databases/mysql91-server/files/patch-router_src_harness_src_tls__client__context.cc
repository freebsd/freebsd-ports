--- router/src/harness/src/tls_client_context.cc.orig	2024-04-10 06:26:28 UTC
+++ router/src/harness/src/tls_client_context.cc
@@ -104,7 +104,7 @@ stdx::expected<void, std::error_code> TlsClientContext
 stdx::expected<void, std::error_code> TlsClientContext::cipher_suites(
     const std::string &ciphers) {
 // TLSv1.3 ciphers are controlled via SSL_CTX_set_ciphersuites()
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 1)
+#ifdef TLS1_3_VERSION
   if (1 != SSL_CTX_set_ciphersuites(ssl_ctx_.get(), ciphers.c_str())) {
     return stdx::unexpected(make_tls_error());
   }
