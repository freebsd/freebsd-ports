qca-ossl: Fix build without SSLv3
http://quickgit.kde.org/?p=qca.git&a=commit&h=20a587d77636186edb044cd2b71d6d90fe98d232

This fixes building with LibreSSL >= 2.3.0 which has removed support
for SSLv3 completely. As far as I know OpenSSL can be configured to
build without it, so it might be helpful there as well.

REVIEW: 125386

qca-ossl: Fix build without support for SHA-0
https://quickgit.kde.org/?p=qca.git&a=commit&h=0dbed8eb38afd1561907a52283091c37e7b85156

LibreSSL >= 2.3.0 removed support for SHA-0, so there's no EVP_sha
anymore.
Wikipedia says about SHA-0: "160-bit hash function published in 1993
under the name SHA. It was withdrawn shortly after publication due to
an undisclosed "significant flaw" and replaced by the slightly revised
version SHA-1.'

REVIEW: 125387

Also includes:
qca-ossl: Remove SHA0 from all_hash_types() when it is not available.
https://git.reviewboard.kde.org/r/128700/

--- plugins/qca-ossl/qca-ossl.cpp.orig	2015-10-02 09:39:21 UTC
+++ plugins/qca-ossl/qca-ossl.cpp
@@ -5403,9 +5403,11 @@ public:
 			ctx = SSL_CTX_new(SSLv2_client_method());
 			break;
 #endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 		case TLS::SSL_v3:
 			ctx = SSL_CTX_new(SSLv3_client_method());
 			break;
+#endif
 		case TLS::TLS_v1:
 			ctx = SSL_CTX_new(TLSv1_client_method());
 			break;
@@ -5805,7 +5807,11 @@ public:
 	{
 		SessionInfo sessInfo;
 
-		sessInfo.isCompressed = (0 != SSL_SESSION_get_compress_id(ssl->session));
+#ifndef OPENSSL_NO_COMP
+		sessInfo.isCompressed = (0 != ssl->session->compress_meth);
+#else
+		sessInfo.isCompressed = 0;
+#endif
 
 		if (ssl->version == TLS1_VERSION)
 			sessInfo.version = TLS::TLS_v1;
@@ -6880,7 +6886,9 @@ static QStringList all_hash_types()
 {
 	QStringList list;
 	list += "sha1";
+#ifdef HAVE_OPENSSL_SHA0
 	list += "sha0";
+#endif
 	list += "ripemd160";
 #ifdef HAVE_OPENSSL_MD2
 	list += "md2";
@@ -7133,8 +7141,10 @@ public:
 			return new opensslInfoContext(this);
 		else if ( type == "sha1" )
 			return new opensslHashContext( EVP_sha1(), this, type);
+#ifdef HAVE_OPENSSL_SHA0
 		else if ( type == "sha0" )
 			return new opensslHashContext( EVP_sha(), this, type);
+#endif
 		else if ( type == "ripemd160" )
 			return new opensslHashContext( EVP_ripemd160(), this, type);
 #ifdef HAVE_OPENSSL_MD2
