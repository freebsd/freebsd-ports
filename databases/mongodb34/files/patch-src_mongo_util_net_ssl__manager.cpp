--- src/mongo/util/net/ssl_manager.cpp.orig	2018-08-29 22:42:21.000000000 +0200
+++ src/mongo/util/net/ssl_manager.cpp	2018-12-23 21:05:48.170857000 +0100
@@ -158,7 +158,7 @@
 #endif // MONGO_CONFIG_NEEDS_ASN1_ANY_DEFINITIONS
 // clang-format on
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 // Copies of OpenSSL after 1.1.0 define new functions for interaction with
 // X509 structure. We must polyfill used definitions to interact with older
 // OpenSSL versions.
