--- router/src/http/src/tls_client_context.cc.orig	2019-09-20 08:30:51 UTC
+++ router/src/http/src/tls_client_context.cc
@@ -54,7 +54,7 @@ void TlsClientContext::verify(TlsVerify verify) {
 
 void TlsClientContext::cipher_suites(const std::string &ciphers) {
 // TLSv1.3 ciphers are controlled via SSL_CTX_set_ciphersuites()
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 1)
+#ifdef TLS1_3_VERSION
   if (1 != SSL_CTX_set_ciphersuites(ssl_ctx_.get(), ciphers.c_str())) {
     throw TlsError("set-cipher-suites");
   }
