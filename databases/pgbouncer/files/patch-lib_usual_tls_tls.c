--- lib/usual/tls/tls.c.orig	2017-05-01 17:37:49 UTC
+++ lib/usual/tls/tls.c
@@ -287,7 +287,7 @@ tls_info_callback(const SSL *ssl, int wh
 {
 	struct tls *ctx = SSL_get_app_data(ssl);
 
-#ifdef USE_LIBSSL_INTERNALS
+#if defined(USE_LIBSSL_INTERNALS) && (!defined(LIBRESSL_VERSION_NUMBER) || LIBRESSL_VERSION_NUMBER < 0x2050100fL)
 	if (!(ctx->state & TLS_HANDSHAKE_COMPLETE) && ssl->s3) {
 		/* steal info about used DH key */
 		if (ssl->s3->tmp.dh && !ctx->used_dh_bits) {
