--- src/qt/qtbase/src/network/ssl/qsslcontext.cpp.orig	2015-01-24 02:19:52 UTC
+++ src/qt/qtbase/src/network/ssl/qsslcontext.cpp
@@ -142,7 +142,11 @@ init_context:
 #endif
         break;
     case QSsl::SslV3:
+#ifndef OPENSSL_NO_SSL3      
         sslContext->ctx = q_SSL_CTX_new(client ? q_SSLv3_client_method() : q_SSLv3_server_method());
+#else
+	sslContext->ctx = 0; // SSL 3 not supported by the system, but chosen deliberately -> error
+#endif
         break;
     case QSsl::SecureProtocols: // SslV2 will be disabled below
     case QSsl::TlsV1SslV3: // SslV2 will be disabled below
