--- src/tds/sec_negotiate_openssl.h.orig	2017-02-15 09:00:01 UTC
+++ src/tds/sec_negotiate_openssl.h
@@ -40,7 +40,7 @@
 static inline const BIGNUM*
 rsa_get_n(const RSA *rsa)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x1010000FL
+#if OPENSSL_VERSION_NUMBER >= 0x1010000FL && !defined(LIBRESSL_VERSION_NUMBER)
 	const BIGNUM *n, *e, *d;
 	RSA_get0_key(rsa, &n, &e, &d);
 	return n;
