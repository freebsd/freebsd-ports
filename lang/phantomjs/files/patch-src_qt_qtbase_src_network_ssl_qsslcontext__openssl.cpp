--- src/qt/qtbase/src/network/ssl/qsslcontext_openssl.cpp.orig	2015-12-12 12:58:05 UTC
+++ src/qt/qtbase/src/network/ssl/qsslcontext_openssl.cpp
@@ -338,7 +338,7 @@ init_context:
 
     const QVector<QSslEllipticCurve> qcurves = sslContext->sslConfiguration.ellipticCurves();
     if (!qcurves.isEmpty()) {
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(OPENSSL_NO_EC)
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(OPENSSL_NO_EC) && !defined(LIBRESSL_VERSION_NUMBER)
         // Set the curves to be used
         if (q_SSLeay() >= 0x10002000L) {
             // SSL_CTX_ctrl wants a non-const pointer as last argument,
