--- router/src/harness/src/tls_client_context.cc.orig	2024-07-12 19:15:25 UTC
+++ router/src/harness/src/tls_client_context.cc
@@ -66,7 +66,7 @@ stdx::expected<void, std::error_code> TlsClientContext
 stdx::expected<void, std::error_code> TlsClientContext::cipher_suites(
     const std::string &ciphers) {
 // TLSv1.3 ciphers are controlled via SSL_CTX_set_ciphersuites()
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 1)
+#ifdef TLS1_3_VERSION
   if (1 != SSL_CTX_set_ciphersuites(ssl_ctx_.get(), ciphers.c_str())) {
     return stdx::make_unexpected(make_tls_error());
   }
