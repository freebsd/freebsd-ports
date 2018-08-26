--- lib/isc/random.c.orig	2013-09-05 05:19:53 UTC
+++ lib/isc/random.c
@@ -68,7 +68,9 @@ isc_random_seed(isc_uint32_t seed)
 #ifndef HAVE_ARC4RANDOM
 	srand(seed);
 #else
+#ifdef arc4random_addrandom
 	arc4random_addrandom((u_char *) &seed, sizeof(isc_uint32_t));
+#endif
 #endif
 }
 
