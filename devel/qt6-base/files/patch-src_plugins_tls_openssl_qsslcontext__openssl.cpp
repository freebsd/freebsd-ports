--- src/plugins/tls/openssl/qsslcontext_openssl.cpp.orig	2025-05-14 09:43:58 UTC
+++ src/plugins/tls/openssl/qsslcontext_openssl.cpp
@@ -36,9 +36,9 @@ int qt_OCSP_status_server_callback(SSL *ssl, void *);
 int qt_OCSP_status_server_callback(SSL *ssl, void *);
 #endif // ocsp
 
-#ifdef TLS1_3_VERSION
+#if defined(TLS1_3_VERSION) && !defined(LIBRESSL_VERSION_NUMBER)
 int q_ssl_sess_set_new_cb(SSL *context, SSL_SESSION *session);
-#endif // TLS1_3_VERSION
+#endif // TLS1_3_VERSION && LIBRESSL_VERSION_NUMBER
 
 } // namespace QTlsPrivate
 
@@ -369,9 +369,11 @@ QT_WARNING_POP
         return;
     }
 
+#ifndef LIBRESSL_VERSION_NUMBER
     // A nasty hacked OpenSSL using a level that will make our auto-tests fail:
     if (q_SSL_CTX_get_security_level(sslContext->ctx) > 1 && *forceSecurityLevel())
         q_SSL_CTX_set_security_level(sslContext->ctx, 1);
+#endif // LIBRESSL_VERSION_NUMBER
 
     const long anyVersion =
 #if QT_CONFIG(dtls)
@@ -662,14 +664,14 @@ QT_WARNING_POP
         q_SSL_CTX_set_verify(sslContext->ctx, verificationMode, verificationCallback);
     }
 
-#ifdef TLS1_3_VERSION
+#if defined(TLS1_3_VERSION) && !defined(LIBRESSL_VERSION_NUMBER)
     // NewSessionTicket callback:
     if (mode == QSslSocket::SslClientMode && !isDtls) {
         q_SSL_CTX_sess_set_new_cb(sslContext->ctx, QTlsPrivate::q_ssl_sess_set_new_cb);
         q_SSL_CTX_set_session_cache_mode(sslContext->ctx, SSL_SESS_CACHE_CLIENT);
     }
 
-#endif // TLS1_3_VERSION
+#endif // TLS1_3_VERSION && LIBRESSL_VERSION_NUMBER
 
 #if QT_CONFIG(dtls)
     // DTLS cookies:
@@ -759,6 +761,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
+#ifndef LIBRESSL_VERSION_NUMBER
     QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
     if (cctx) {
         q_SSL_CONF_CTX_set_ssl_ctx(cctx.data(), sslContext->ctx);
@@ -802,7 +805,9 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
             sslContext->errorStr = msgErrorSettingBackendConfig(QSslSocket::tr("SSL_CONF_finish() failed"));
             sslContext->errorCode = QSslError::UnspecifiedError;
         }
-    } else {
+    } else
+#endif // LIBRESSL_VERSION_NUMBER
+    {
         sslContext->errorStr = msgErrorSettingBackendConfig(QSslSocket::tr("SSL_CONF_CTX_new() failed"));
         sslContext->errorCode = QSslError::UnspecifiedError;
     }
