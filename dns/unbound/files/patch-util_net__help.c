--- util/net_help.c.orig	2015-07-21 14:37:15 UTC
+++ util/net_help.c
@@ -619,16 +619,20 @@ void* listen_sslctx_create(char* key, ch
 		return NULL;
 	}
 	/* no SSLv2, SSLv3 because has defects */
+#ifndef OPENSSL_NO_SSL2
 	if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2) & SSL_OP_NO_SSLv2)){
 		log_crypto_err("could not set SSL_OP_NO_SSLv2");
 		SSL_CTX_free(ctx);
 		return NULL;
 	}
+#endif
+#ifndef OPENSSL_NO_SSL3
 	if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3) & SSL_OP_NO_SSLv3)){
 		log_crypto_err("could not set SSL_OP_NO_SSLv3");
 		SSL_CTX_free(ctx);
 		return NULL;
 	}
+#endif
 	if(!SSL_CTX_use_certificate_chain_file(ctx, pem)) {
 		log_err("error for cert file: %s", pem);
 		log_crypto_err("error in SSL_CTX use_certificate_chain_file");
@@ -690,16 +694,20 @@ void* connect_sslctx_create(char* key, c
 		log_crypto_err("could not allocate SSL_CTX pointer");
 		return NULL;
 	}
+#ifndef OPENSSL_NO_SSL2
 	if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2) & SSL_OP_NO_SSLv2)) {
 		log_crypto_err("could not set SSL_OP_NO_SSLv2");
 		SSL_CTX_free(ctx);
 		return NULL;
 	}
+#endif
+#ifndef OPENSSL_NO_SSL3
 	if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3) & SSL_OP_NO_SSLv3)) {
 		log_crypto_err("could not set SSL_OP_NO_SSLv3");
 		SSL_CTX_free(ctx);
 		return NULL;
 	}
+#endif
 	if(key && key[0]) {
 		if(!SSL_CTX_use_certificate_chain_file(ctx, pem)) {
 			log_err("error in client certificate %s", pem);
