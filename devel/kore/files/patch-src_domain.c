Remove when FreeBSD 10.4 is EOL.

--- src/domain.c.orig	2018-07-19 08:34:48 UTC
+++ src/domain.c
@@ -774,7 +774,7 @@ domain_load_certificate_chain(SSL_CTX *ctx, const void
 	if (SSL_CTX_use_certificate(ctx, x) == 0)
 		fatal("SSL_CTX_use_certificate: %s", ssl_errno_s);
 
-#if defined(LIBRESSL_VERSION_TEXT)
+#if defined(LIBRESSL_VERSION_TEXT) || OPENSSL_VERSION_NUMBER <= 0x1000115fL
 	sk_X509_pop_free(ctx->extra_certs, X509_free);
 	ctx->extra_certs = NULL;
 #else
@@ -784,7 +784,7 @@ domain_load_certificate_chain(SSL_CTX *ctx, const void
 	ERR_clear_error();
 	while ((ca = PEM_read_bio_X509(in, NULL, NULL, NULL)) != NULL) {
 		/* ca its reference count won't be increased. */
-#if defined(LIBRESSL_VERSION_TEXT)
+#if defined(LIBRESSL_VERSION_TEXT) || OPENSSL_VERSION_NUMBER <= 0x1000115fL
 		if (SSL_CTX_add_extra_chain_cert(ctx, ca) == 0)
 			fatal("SSL_CTX_add_extra_chain_cert: %s", ssl_errno_s);
 #else
