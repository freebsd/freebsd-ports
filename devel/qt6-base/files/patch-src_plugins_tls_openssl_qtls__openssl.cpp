--- src/plugins/tls/openssl/qtls_openssl.cpp.orig	2025-05-14 09:43:58 UTC
+++ src/plugins/tls/openssl/qtls_openssl.cpp
@@ -1435,13 +1435,13 @@ bool TlsCryptographOpenSSL::initSslContext()
     else if (mode == QSslSocket::SslServerMode)
         q_SSL_set_psk_server_callback(ssl, &q_ssl_psk_server_callback);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101006L
+#if OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
     // Set the client callback for TLSv1.3 PSK
     if (mode == QSslSocket::SslClientMode
         && QSslSocket::sslLibraryBuildVersionNumber() >= 0x10101006L) {
         q_SSL_set_psk_use_session_callback(ssl, &q_ssl_psk_use_session_callback);
     }
-#endif // openssl version >= 0x10101006L
+#endif // OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
 
 #endif // OPENSSL_NO_PSK
 
