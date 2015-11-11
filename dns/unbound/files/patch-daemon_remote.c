--- daemon/remote.c.orig	2015-09-25 12:39:10 UTC
+++ daemon/remote.c
@@ -208,16 +208,20 @@ daemon_remote_create(struct config_file*
 		return NULL;
 	}
 	/* no SSLv2, SSLv3 because has defects */
+#ifndef OPENSSL_NO_SSL2
 	if(!(SSL_CTX_set_options(rc->ctx, SSL_OP_NO_SSLv2) & SSL_OP_NO_SSLv2)){
 		log_crypto_err("could not set SSL_OP_NO_SSLv2");
 		daemon_remote_delete(rc);
 		return NULL;
 	}
+#endif
+#ifndef OPENSSL_NO_SSL3
 	if(!(SSL_CTX_set_options(rc->ctx, SSL_OP_NO_SSLv3) & SSL_OP_NO_SSLv3)){
 		log_crypto_err("could not set SSL_OP_NO_SSLv3");
 		daemon_remote_delete(rc);
 		return NULL;
 	}
+#endif
 
 	if (cfg->remote_control_use_cert == 0) {
 		/* No certificates are requested */
