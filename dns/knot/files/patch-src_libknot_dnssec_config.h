--- src/libknot/dnssec/config.h.orig	2015-04-08 11:57:44 UTC
+++ src/libknot/dnssec/config.h
@@ -40,7 +40,7 @@
   #undef KNOT_ENABLE_ECDSA
 #endif
 
-#if !defined(OPENSSL_NO_GOST) && OPENSSL_VERSION_NUMBER >= 0x1000001fL
+#if !defined(OPENSSL_NO_GOST) && OPENSSL_VERSION_NUMBER >= 0x1000001fL && !defined(LIBRESSL_VERSION_NUMBER)
   #define KNOT_ENABLE_GOST 1
 #else
   #undef KNOT_ENABLE_GOST
