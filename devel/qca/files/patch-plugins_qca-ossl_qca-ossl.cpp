--- plugins/qca-ossl/qca-ossl.cpp.orig	2014-11-06 09:15:45.000000000 +0100
+++ plugins/qca-ossl/qca-ossl.cpp	2015-09-10 15:45:43.347311582 +0200
@@ -5399,11 +5399,13 @@ public:
 			ctx = SSL_CTX_new(SSLv2_client_method());
 			break;
 #endif
+#ifndef OPENSSL_NO_SSL3
 		case TLS::SSL_v3:
 			ctx = SSL_CTX_new(SSLv3_client_method());
 			break;
+#endif
 		case TLS::TLS_v1:
-			ctx = SSL_CTX_new(TLSv1_client_method());
+			ctx = SSL_CTX_new(SSLv23_client_method());
 			break;
 		case TLS::DTLS_v1:
 		default:
@@ -5801,7 +5803,7 @@ public:
 	{
 		SessionInfo sessInfo;
 
-		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(ssl->session));
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
@@ -7297,7 +7299,7 @@ public:
 			return new CMSContext( this );
 		else if ( type == "ca" )
 			return new MyCAContext( this );
-		return 0;
+		return NULL;
 	}
 };
 
