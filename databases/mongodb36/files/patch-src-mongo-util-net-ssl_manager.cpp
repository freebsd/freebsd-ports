--- src/mongo/util/net/ssl_manager.cpp.orig	2018-07-08 16:33:48.347433000 +0000
+++ src/mongo/util/net/ssl_manager.cpp	2018-07-08 16:34:49.098494000 +0000
@@ -237,7 +237,7 @@
 #endif // MONGO_CONFIG_NEEDS_ASN1_ANY_DEFINITIONS
 // clang-format on
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 // Copies of OpenSSL after 1.1.0 define new functions for interaction with
 // X509 structure. We must polyfill used definitions to interact with older
 // OpenSSL versions.
