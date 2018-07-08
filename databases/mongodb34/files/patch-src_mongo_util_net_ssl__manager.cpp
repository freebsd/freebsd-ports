--- src/mongo/util/net/ssl_manager.cpp.orig	2017-06-08 16:11:03 UTC
+++ src/mongo/util/net/ssl_manager.cpp
@@ -125,7 +125,7 @@ IMPLEMENT_ASN1_ENCODE_FUNCTIONS_const_fname(ASN1_SEQUE
 #endif // MONGO_CONFIG_NEEDS_ASN1_ANY_DEFINITIONS
 // clang-format on
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined (LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 // Copies of OpenSSL after 1.1.0 define new functions for interaction with
 // X509 structure. We must polyfill used definitions to interact with older
 // OpenSSL versions.
