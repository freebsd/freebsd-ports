$OpenBSD: patch-ext_openssl_xp_ssl_c,v 1.2 2015/07/19 20:09:58 sthen Exp $
--- ext/openssl/xp_ssl.c.orig.port	Sat Jul 18 13:58:31 2015
+++ ext/openssl/xp_ssl.c	Sat Jul 18 14:52:03 2015
@@ -339,9 +339,14 @@ static inline int php_openssl_setup_crypto(php_stream 
 			break;
 #endif
 		case STREAM_CRYPTO_METHOD_SSLv3_CLIENT:
+#ifdef OPENSSL_NO_SSL3
+			php_error_docref(NULL TSRMLS_CC, E_WARNING, "SSLv3 support is not compiled into the OpenSSL library PHP is linked against");
+			return -1;
+#else
 			sslsock->is_client = 1;
 			method = SSLv3_client_method();
 			break;
+#endif
 		case STREAM_CRYPTO_METHOD_TLS_CLIENT:
 			sslsock->is_client = 1;
 			method = TLSv1_client_method();
@@ -351,9 +356,14 @@ static inline int php_openssl_setup_crypto(php_stream 
 			method = SSLv23_server_method();
 			break;
 		case STREAM_CRYPTO_METHOD_SSLv3_SERVER:
+#ifdef OPENSSL_NO_SSL3
+			php_error_docref(NULL TSRMLS_CC, E_WARNING, "SSLv3 support is not compiled into the OpenSSL library PHP is linked against");
+			return -1;
+#else
 			sslsock->is_client = 0;
 			method = SSLv3_server_method();
 			break;
+#endif
 		case STREAM_CRYPTO_METHOD_SSLv2_SERVER:
 #ifdef OPENSSL_NO_SSL2
 			php_error_docref(NULL TSRMLS_CC, E_WARNING, "SSLv2 support is not compiled into the OpenSSL library PHP is linked against");
