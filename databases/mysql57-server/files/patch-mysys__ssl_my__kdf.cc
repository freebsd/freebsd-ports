--- mysys_ssl/my_kdf.cc.orig	2022-11-04 07:47:44 UTC
+++ mysys_ssl/my_kdf.cc
@@ -59,7 +59,7 @@ int create_kdf_key(const unsigned char *key, const uns
   Key_derivation_function *kdf_function = NULL;
 
   if (kdf_name == "hkdf") {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
     kdf_function = new Key_hkdf_function(kdf_options);
 #else
     return 1;
@@ -87,7 +87,7 @@ Key_derivation_function::Key_derivation_function() {
   options_valid_ = false;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 Key_hkdf_function::Key_hkdf_function(vector<string> *kdf_options) {
   kdf_options_ = kdf_options;
 }
