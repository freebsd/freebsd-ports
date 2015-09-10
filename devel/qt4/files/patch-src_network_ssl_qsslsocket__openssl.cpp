$OpenBSD: patch-src_network_ssl_qsslsocket_openssl_cpp,v 1.2 2015/06/03 07:28:01 dcoppa Exp $
Disable SSLv3 by default.
--- src/network/ssl/qsslsocket_openssl.cpp.orig	Thu May  7 16:14:44 2015
+++ src/network/ssl/qsslsocket_openssl.cpp	Sun May 31 13:28:29 2015
@@ -269,13 +269,13 @@ init_context:
     case QSsl::SslV3:
         ctx = q_SSL_CTX_new(client ? q_SSLv3_client_method() : q_SSLv3_server_method());
         break;
-    case QSsl::SecureProtocols: // SslV2 will be disabled below
-    case QSsl::TlsV1SslV3: // SslV2 will be disabled below
     case QSsl::AnyProtocol:
-    default:
         ctx = q_SSL_CTX_new(client ? q_SSLv23_client_method() : q_SSLv23_server_method());
         break;
     case QSsl::TlsV1:
+    case QSsl::SecureProtocols:
+    case QSsl::TlsV1SslV3:
+    default:
         ctx = q_SSL_CTX_new(client ? q_TLSv1_client_method() : q_TLSv1_server_method());
         break;
     }
