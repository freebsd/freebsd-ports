--- ext/openssl/openssl_missing.h.orig	2009-01-11 20:16:56.000000000 -0500
+++ ext/openssl/openssl_missing.h	2009-01-11 20:17:30.000000000 -0500
@@ -120,8 +120,8 @@
 int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx);
 int BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m, BN_CTX *ctx);
 int BN_mod_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m, BN_CTX *ctx);
-int BN_rand_range(BIGNUM *r, BIGNUM *range);
-int BN_pseudo_rand_range(BIGNUM *r, BIGNUM *range);
+int BN_rand_range(BIGNUM *r, const BIGNUM *range);
+int BN_pseudo_rand_range(BIGNUM *r, const BIGNUM *range);
 char *CONF_get1_default_config_file(void);
 int PEM_def_callback(char *buf, int num, int w, void *key);
 
