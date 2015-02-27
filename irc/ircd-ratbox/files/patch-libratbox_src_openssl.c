--- libratbox/src/openssl.c.orig	2012-03-16 07:29:42.000000000 +0100
+++ libratbox/src/openssl.c	2015-02-27 11:53:15.392149829 +0100
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
