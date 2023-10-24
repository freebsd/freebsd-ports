--- src/plugins/tls/openssl/qopenssl_p.h.orig	2023-09-21 19:24:26 UTC
+++ src/plugins/tls/openssl/qopenssl_p.h
@@ -70,6 +70,13 @@ QT_BEGIN_NAMESPACE
 
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
