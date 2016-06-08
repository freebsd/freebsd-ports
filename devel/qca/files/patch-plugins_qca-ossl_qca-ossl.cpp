--- plugins/qca-ossl/qca-ossl.cpp.orig	2015-11-12 20:19:43 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -5403,11 +5403,13 @@ public:
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
@@ -7137,8 +7139,10 @@ public:
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
@@ -7305,7 +7309,7 @@ public:
 			return new CMSContext( this );
 		else if ( type == "ca" )
 			return new MyCAContext( this );
-		return 0;
+		return NULL;
 	}
 };
 
