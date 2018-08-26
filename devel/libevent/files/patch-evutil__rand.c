--- evutil_rand.c.orig	2017-01-25 23:37:15 UTC
+++ evutil_rand.c
@@ -195,8 +195,10 @@ evutil_secure_rng_get_bytes(void *buf, size_t n)
 void
 evutil_secure_rng_add_bytes(const char *buf, size_t n)
 {
+#ifdef arc4random_addrandom
 	arc4random_addrandom((unsigned char*)buf,
 	    n>(size_t)INT_MAX ? INT_MAX : (int)n);
+#endif
 }
 
 void
