From f87624a459342de33ff58619901da96749fad057 Mon Sep 17 00:00:00 2001
From: Joris Vink <joris@coders.se>
Date: Mon, 1 Oct 2018 10:36:33 +0200
Subject: [PATCH] Add missing KORE_NO_TLS guards.

Fixes NOTLS=1 builds on openssl 1.1.1
---
 src/domain.c | 4 ++++
 1 file changed, 4 insertions(+)

With some additional changes to fix build with OpenSSL 1.0.1u on
FreeBSD 10.4.

--- src/domain.c.orig	2018-07-18 14:25:49 UTC
+++ src/domain.c
@@ -125,6 +125,7 @@ kore_domain_init(void)
 {
 	TAILQ_INIT(&domains);
 
+#if !defined(KORE_NO_TLS)
 #if !defined(LIBRESSL_VERSION_TEXT) && OPENSSL_VERSION_NUMBER >= 0x10100000L
 	if (keymgr_rsa_meth == NULL) {
 		if ((keymgr_rsa_meth = RSA_meth_new("kore RSA keymgr method",
@@ -143,6 +144,7 @@ kore_domain_init(void)
 
 	EC_KEY_METHOD_set_sign(keymgr_ec_meth, NULL, NULL, keymgr_ecdsa_sign);
 #endif
+#endif
 }
 
 void
@@ -155,6 +157,7 @@ kore_domain_cleanup(void)
 		kore_domain_free(dom);
 	}
 
+#if !defined(KORE_NO_TLS)
 #if !defined(LIBRESSL_VERSION_TEXT) && OPENSSL_VERSION_NUMBER >= 0x10100000L
 	if (keymgr_rsa_meth != NULL) {
 		RSA_meth_free(keymgr_rsa_meth);
@@ -166,6 +169,7 @@ kore_domain_cleanup(void)
 		keymgr_ec_meth = NULL;
 	}
 #endif
+#endif
 }
 
 int
@@ -774,7 +778,7 @@ domain_load_certificate_chain(SSL_CTX *ctx, const void
 	if (SSL_CTX_use_certificate(ctx, x) == 0)
 		fatal("SSL_CTX_use_certificate: %s", ssl_errno_s);
 
-#if defined(LIBRESSL_VERSION_TEXT)
+#if defined(LIBRESSL_VERSION_TEXT) || OPENSSL_VERSION_NUMBER <= 0x1000115fL
 	sk_X509_pop_free(ctx->extra_certs, X509_free);
 	ctx->extra_certs = NULL;
 #else
@@ -784,7 +788,7 @@ domain_load_certificate_chain(SSL_CTX *ctx, const void
 	ERR_clear_error();
 	while ((ca = PEM_read_bio_X509(in, NULL, NULL, NULL)) != NULL) {
 		/* ca its reference count won't be increased. */
-#if defined(LIBRESSL_VERSION_TEXT)
+#if defined(LIBRESSL_VERSION_TEXT) || OPENSSL_VERSION_NUMBER <= 0x1000115fL
 		if (SSL_CTX_add_extra_chain_cert(ctx, ca) == 0)
 			fatal("SSL_CTX_add_extra_chain_cert: %s", ssl_errno_s);
 #else
