--- src/xstd/Ssl.cc.orig	2014-10-22 23:22:22 UTC
+++ src/xstd/Ssl.cc
@@ -38,9 +38,11 @@ SslCtx::SslCtx(SslProtocol protocol, con
 		case TLSv1:
 			theCtx = ::SSL_CTX_new(::TLSv1_method());
 			break;
+#ifndef OPENSSL_NO_SSL3
 		case SSLv3:
 			theCtx = ::SSL_CTX_new(::SSLv3_method());
 			break;
+#endif
 		case SSLv23:
 			theCtx = ::SSL_CTX_new(::SSLv23_method());
 			break;
