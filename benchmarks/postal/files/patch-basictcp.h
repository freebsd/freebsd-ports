--- basictcp.h.orig	2013-12-08 18:49:04.000000000 +0900
+++ basictcp.h	2013-12-08 18:49:33.000000000 +0900
@@ -89,7 +89,11 @@
 
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
