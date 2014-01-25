--- tcp.h.orig
+++ tcp.h
@@ -100,7 +100,11 @@
 
 #ifdef USE_SSL
 #ifdef USE_OPENSSL
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+  const SSL_METHOD *m_sslMeth;
+#else
   SSL_METHOD *m_sslMeth;
+#endif
   SSL_CTX* m_sslCtx;
   SSL *m_ssl;
 #else
