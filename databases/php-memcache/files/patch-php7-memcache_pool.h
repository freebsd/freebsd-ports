--- php7/memcache_pool.h.orig	2019-02-27 20:19:05 UTC
+++ php7/memcache_pool.h
@@ -396,7 +396,7 @@ int mmc_unpack_value(mmc_t *, mmc_reques
 double timeval_to_double(struct timeval tv);
 struct timeval double_to_timeval(double sec);
 
-int mmc_prepare_key_ex(const char *, unsigned int, char *, unsigned int *);
+int mmc_prepare_key_ex(const char *, unsigned int, char *, unsigned int *, char *);
 int mmc_prepare_key(zval *, char *, unsigned int *);
 
 #define mmc_str_left(h, n, hlen, nlen) ((hlen) >= (nlen) ? memcmp((h), (n), (nlen)) == 0 : 0)
