--- libratbox/src/openssl.c.orig	2008-12-10 20:33:21 UTC
+++ libratbox/src/openssl.c
@@ -557,7 +557,9 @@ rb_init_prng(const char *path, prng_seed
 	switch (seed_type)
 	{
 	case RB_PRNG_EGD:
+#ifndef OPENSSL_NO_EGD
 		if(RAND_egd(path) == -1)
+#endif
 			return -1;
 		break;
 	case RB_PRNG_FILE:
