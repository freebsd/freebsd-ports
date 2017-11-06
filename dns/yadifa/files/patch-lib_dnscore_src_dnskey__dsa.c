--- lib/dnscore/src/dnskey_dsa.c.orig	2016-12-16 11:52:17 UTC
+++ lib/dnscore/src/dnskey_dsa.c
@@ -70,7 +70,7 @@
 #error "OPENSSL_VERSION_NUMBER not defined"
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 
 /*
  * Backward-compatible interface for 0.9.x
@@ -226,7 +226,7 @@ dnskey_dsa_genkey(u32 size)
     int err;
     DSA* dsa;
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
     dsa = DSA_generate_parameters(size, NULL,0, NULL, NULL, NULL, NULL);
 #else
     dsa = DSA_new();
