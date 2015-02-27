--- libratbox/src/openssl.c.orig	2008-12-10 21:33:21.000000000 +0100
+++ libratbox/src/openssl.c	2015-02-27 11:55:05.517146069 +0100
@@ -557,8 +557,7 @@
 	switch (seed_type)
 	{
 	case RB_PRNG_EGD:
-		if(RAND_egd(path) == -1)
-			return -1;
+		return -1;
 		break;
 	case RB_PRNG_FILE:
 		if(RAND_load_file(path, -1) == -1)
