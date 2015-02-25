--- src/random.c.orig	2014-07-26 17:42:10.000000000 +0200
+++ src/random.c	2015-02-25 20:49:36.769099626 +0100
@@ -163,7 +163,7 @@
 void init_random()
 {
 struct {
-#ifdef USE_SSL
+#if defined(USE_SSL)
 	char egd[32];			/* from EGD */
 #endif
 #ifndef _WIN32
@@ -187,7 +187,7 @@
 
 	/* Grab non-OS specific "random" data */
 #ifdef USE_SSL
- #if OPENSSL_VERSION_NUMBER >= 0x000907000
+ #if OPENSSL_VERSION_NUMBER >= 0x000907000 && defined(HAVE_RAND_EGD)
 	if (EGD_PATH) {
 		n = RAND_query_egd_bytes(EGD_PATH, rdat.egd, sizeof(rdat.egd));
 	}
