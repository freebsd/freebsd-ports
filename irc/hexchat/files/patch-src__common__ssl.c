--- src/common/ssl.c.orig	2016-12-10 14:30:51 UTC
+++ src/common/ssl.c
@@ -176,7 +176,7 @@ _SSL_get_cert_info (struct cert_info *ce
 		return 1;
 
 	alg = OBJ_obj2nid (algor->algorithm);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER
 	sign_alg = OBJ_obj2nid (peer_cert->sig_alg->algorithm);
 #else
 	sign_alg = X509_get_signature_nid (peer_cert);
@@ -306,7 +306,7 @@ _SSL_socket (SSL_CTX *ctx, int sd)
 
 	SSL_set_fd (ssl, sd);
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || LIBRESSL_VERSION_NUMBER
 	method = ctx->method;
 #else
 	method = SSL_CTX_get_ssl_method (ctx);
@@ -328,7 +328,7 @@ _SSL_set_verify (SSL_CTX *ctx, void *ver
 		__SSL_fill_err_buf ("SSL_CTX_set_default_verify_paths");
 		return (err_buf);
 	}
-/*
+
 	if (cacert)
 	{
 		if (!SSL_CTX_load_verify_locations (ctx, cacert, NULL))
@@ -337,7 +337,7 @@ _SSL_set_verify (SSL_CTX *ctx, void *ver
 			return (err_buf);
 		}
 	}
-*/
+
 	SSL_CTX_set_verify (ctx, SSL_VERIFY_PEER, verify_callback);
 
 	return (NULL);
