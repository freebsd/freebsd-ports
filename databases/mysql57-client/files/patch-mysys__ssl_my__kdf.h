--- mysys_ssl/my_kdf.h.orig	2022-11-04 07:35:11 UTC
+++ mysys_ssl/my_kdf.h
@@ -61,7 +61,7 @@ class Key_derivation_function {
   bool options_valid_;
 };
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 
 /** Class to implement KDF method hkdf. */
 class Key_hkdf_function : public Key_derivation_function {
