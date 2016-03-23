--- libratbox/src/openssl.c.orig	2012-03-16 07:29:42.000000000 +0100
+++ libratbox/src/openssl.c	2015-03-10 21:01:33.572383130 +0100
@@ -556,10 +556,12 @@
 
 	switch (seed_type)
 	{
+#ifndef OPENSSL_NO_EGD
 	case RB_PRNG_EGD:
 		if(RAND_egd(path) == -1)
 			return -1;
 		break;
+#endif
 	case RB_PRNG_FILE:
 		if(RAND_load_file(path, -1) == -1)
 			return -1;
