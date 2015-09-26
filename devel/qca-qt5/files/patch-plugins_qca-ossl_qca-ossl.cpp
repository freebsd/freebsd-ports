--- plugins/qca-ossl/qca-ossl.cpp.orig	2014-11-06 08:15:45 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -5399,9 +5399,11 @@ public:
 			ctx = SSL_CTX_new(SSLv2_client_method());
 			break;
 #endif
+#ifndef OPENSSL_NO_SSL3
 		case TLS::SSL_v3:
 			ctx = SSL_CTX_new(SSLv3_client_method());
 			break;
+#endif
 		case TLS::TLS_v1:
 			ctx = SSL_CTX_new(TLSv1_client_method());
 			break;
@@ -5801,7 +5803,11 @@ public:
 	{
 		SessionInfo sessInfo;
 
+#ifndef OPENSSL_NO_COMP
 		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+#else
+		sessInfo.isCompressed = 0;
+#endif
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
@@ -7129,8 +7135,10 @@ public:
 			return new opensslInfoContext(this);
 		else if ( type == "sha1" )
 			return new opensslHashContext( EVP_sha1(), this, type);
+#ifndef OPENSSL_NO_SHA0 
 		else if ( type == "sha0" )
 			return new opensslHashContext( EVP_sha(), this, type);
+#endif
 		else if ( type == "ripemd160" )
 			return new opensslHashContext( EVP_ripemd160(), this, type);
 #ifdef HAVE_OPENSSL_MD2
