--- basictcp.h.orig	2008-05-26 09:41:40 UTC
+++ basictcp.h
@@ -89,7 +89,11 @@ private:
 
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
