--- src/plugins/tls/openssl/qopenssl_p.h.orig	2025-05-14 09:43:58 UTC
+++ src/plugins/tls/openssl/qopenssl_p.h
@@ -71,6 +71,13 @@ QT_BEGIN_NAMESPACE
 
 QT_BEGIN_NAMESPACE
 
+#ifndef DTLS_ANY_VERSION
+#define DTLS_ANY_VERSION 0x1FFFF
+#endif
+#ifndef TLS_ANY_VERSION
+#define TLS_ANY_VERSION 0x10000
+#endif
+
 struct QSslErrorEntry {
     int code = 0;
     int depth = 0;
