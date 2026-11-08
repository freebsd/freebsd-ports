--- src/plugins/tls/openssl/qopenssl_p.h.orig	2026-05-11 20:54:55 UTC
+++ src/plugins/tls/openssl/qopenssl_p.h
@@ -77,6 +77,13 @@ QT_BEGIN_NAMESPACE
 
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
