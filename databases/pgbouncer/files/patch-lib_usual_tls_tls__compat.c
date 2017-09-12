--- lib/usual/tls/tls_compat.c.orig	2016-02-24 18:26:21 UTC
+++ lib/usual/tls/tls_compat.c
@@ -144,7 +144,7 @@ long SSL_CTX_set_dh_auto(SSL_CTX *ctx, i
 
 static EC_KEY *ecdh_cache;
 
-#ifdef USE_LIBSSL_INTERNALS
+#ifdef USE_LIBSSL_OLD
 static EC_KEY *ecdh_auto_cb(SSL *ssl, int is_export, int keylength)
 {
 	int last_nid;
@@ -187,7 +187,7 @@ long SSL_CTX_set_ecdh_auto(SSL_CTX *ctx,
 {
 	if (onoff) {
 		SSL_CTX_set_options(ctx, SSL_OP_SINGLE_ECDH_USE);
-#ifdef USE_LIBSSL_INTERNALS
+#ifdef USE_LIBSSL_OLD
 		SSL_CTX_set_tmp_ecdh_callback(ctx, ecdh_auto_cb);
 #endif
 	}
@@ -226,7 +226,7 @@ SSL_CTX_use_certificate_chain_mem(SSL_CT
 	BIO *bio = NULL;
 	int ok;
 
-#ifdef USE_LIBSSL_INTERNALS
+#ifdef USE_LIBSSL_OLD
 	psw_fn = ctx->default_passwd_callback;
 	psw_arg = ctx->default_passwd_callback_userdata;
 #endif
