--- src/libknot/dnssec/crypto.c.orig	2015-04-08 11:57:44 UTC
+++ src/libknot/dnssec/crypto.c
@@ -122,7 +122,14 @@ static unsigned long openssl_threadid_cb(void)
 
 /*- pluggable engines -------------------------------------------------------*/
 
-#if KNOT_ENABLE_GOST
+#if KNOT_ENABLE_GOST && !defined(LIBRESSL_VERSION_NUMBER)
+  #define KNOT_LOAD_GOST 1
+#else
+  #undef KNOT_LOAD_GOST
+#endif
+
+
+#if KNOT_LOAD_GOST
 
 static ENGINE *gost_engine = NULL;
 
@@ -130,6 +137,8 @@ static void init_gost_engine(void)
 {
 	assert(gost_engine == NULL);
 
+	ENGINE_load_builtin_engines();
+
 #ifndef OPENSSL_NO_STATIC_ENGINE
 	ENGINE_load_gost();
 #else
@@ -206,16 +215,19 @@ void knot_crypto_cleanup_threads(void)
 
 void knot_crypto_load_engines(void)
 {
-#if KNOT_ENABLE_GOST
+#if KNOT_LOAD_GOST
 	if (!gost_engine) {
 		init_gost_engine();
 	}
 #endif
+#if KNOT_ENABLE_GOST
+	OpenSSL_add_all_algorithms();
+#endif
 }
 
 void knot_crypto_unload_engines(void)
 {
-#if KNOT_ENABLE_GOST
+#if KNOT_LOAD_GOST
 	if (gost_engine) {
 		deinit_gost_engine();
 	}

