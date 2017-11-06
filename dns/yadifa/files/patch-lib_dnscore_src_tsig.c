--- lib/dnscore/src/tsig.c.orig	2016-12-16 11:52:17 UTC
+++ lib/dnscore/src/tsig.c
@@ -233,7 +233,7 @@
 tsig_hmac_t
 tsig_hmac_allocate()
 {
-#if OPENSSL_VERSION_NUMBER < 0x10100000L // ie: 0.9.x
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) // ie: 0.9.x
     HMAC_CTX *hmac;
     ZALLOC_OR_DIE(HMAC_CTX*, hmac, HMAC_CTX, GENERIC_TAG);
     HMAC_CTX_init(hmac);
@@ -257,7 +257,7 @@ tsig_hmac_free(tsig_hmac_t t)
 {
     HMAC_CTX *hmac = (HMAC_CTX*)t;
     yassert(hmac != NULL);
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     HMAC_CTX_cleanup(hmac);
     ZFREE(t, HMAC_CTX);
 #else
@@ -268,7 +268,7 @@ tsig_hmac_free(tsig_hmac_t t)
 void tsig_hmac_reset(tsig_hmac_t t)
 {
     HMAC_CTX *hmac = (HMAC_CTX*)t;
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     HMAC_CTX_cleanup(hmac);
     HMAC_CTX_init(hmac);
 #else
