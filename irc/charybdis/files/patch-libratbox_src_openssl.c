--- libratbox/src/openssl.c.orig	2012-12-31 22:47:31.000000000 +0100
+++ libratbox/src/openssl.c	2015-02-27 21:36:08.560642429 +0100
@@ -577,8 +577,7 @@
 	switch (seed_type)
 	{
 	case RB_PRNG_EGD:
-		if(RAND_egd(path) == -1)
-			return -1;
+		return -1;
 		break;
 	case RB_PRNG_FILE:
 		if(RAND_load_file(path, -1) == -1)
