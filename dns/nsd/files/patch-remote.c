--- remote.c.orig	2015-08-05 13:00:42 UTC
+++ remote.c
@@ -262,17 +262,21 @@ daemon_remote_create(nsd_options_t* cfg)
 		free(rc);
 		return NULL;
 	}
+#ifndef OPENSSL_NO_SSL2
 	/* no SSLv2, SSLv3 because has defects */
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
 	s_cert = cfg->server_cert_file;
 	s_key = cfg->server_key_file;
 	VERBOSITY(2, (LOG_INFO, "setup SSL certificates"));
