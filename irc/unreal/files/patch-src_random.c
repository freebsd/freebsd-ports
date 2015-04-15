--- src/random.c.orig	2014-07-26 15:42:10 UTC
+++ src/random.c
@@ -163,7 +163,7 @@ unsigned char mdbuf[16];
 void init_random()
 {
 struct {
-#ifdef USE_SSL
+#if defined(USE_SSL)
 	char egd[32];			/* from EGD */
 #endif
 #ifndef _WIN32
@@ -187,7 +187,7 @@ MEMORYSTATUS mstat;
 
 	/* Grab non-OS specific "random" data */
 #ifdef USE_SSL
- #if OPENSSL_VERSION_NUMBER >= 0x000907000
+ #if OPENSSL_VERSION_NUMBER >= 0x000907000 && defined(HAVE_RAND_EGD)
 	if (EGD_PATH) {
 		n = RAND_query_egd_bytes(EGD_PATH, rdat.egd, sizeof(rdat.egd));
 	}
