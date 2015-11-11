--- smallapp/unbound-control.c.orig	2015-07-18 12:34:37 UTC
+++ smallapp/unbound-control.c
@@ -156,11 +156,15 @@ setup_ctx(struct config_file* cfg)
         ctx = SSL_CTX_new(SSLv23_client_method());
 	if(!ctx)
 		ssl_err("could not allocate SSL_CTX pointer");
+#ifndef OPENSSL_NO_SSL2
         if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv2) & SSL_OP_NO_SSLv2))
 		ssl_err("could not set SSL_OP_NO_SSLv2");
+#endif
         if(cfg->remote_control_use_cert) {
+#ifndef OPENSSL_NO_SSL3
 		if(!(SSL_CTX_set_options(ctx, SSL_OP_NO_SSLv3) & SSL_OP_NO_SSLv3))
 			ssl_err("could not set SSL_OP_NO_SSLv3");
+#endif
 		if(!SSL_CTX_use_certificate_chain_file(ctx,c_cert) ||
 		    !SSL_CTX_use_PrivateKey_file(ctx,c_key,SSL_FILETYPE_PEM)
 		    || !SSL_CTX_check_private_key(ctx))
