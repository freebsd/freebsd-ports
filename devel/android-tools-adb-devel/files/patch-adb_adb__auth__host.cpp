--- adb/adb_auth_host.cpp.orig	2016-06-29 23:43:15 UTC
+++ adb/adb_auth_host.cpp
@@ -34,7 +34,9 @@
 #include <android-base/stringprintf.h>
 #include <android-base/strings.h>
 #include <crypto_utils/android_pubkey.h>
+#if defined(OPENSSL_IS_BORINGSSL)
 #include <openssl/base64.h>
+#endif
 #include <openssl/evp.h>
 #include <openssl/objects.h>
 #include <openssl/pem.h>
@@ -70,6 +72,30 @@ static std::string get_user_info() {
     return " " + username + "@" + hostname;
 }
 
+#if !defined(OPENSSL_IS_BORINGSSL)
+// https://boringssl.googlesource.com/boringssl/+/6601402%5E!/
+static int EVP_EncodedLength(size_t *out_len, size_t len) {
+  if (len + 2 < len) {
+    return 0;
+  }
+  len += 2;
+  len /= 3;
+
+  if (((len << 2) >> 2) != len) {
+    return 0;
+  }
+  len <<= 2;
+
+  if (len + 1 < len) {
+    return 0;
+  }
+  len++;
+
+  *out_len = len;
+  return 1;
+}
+#endif
+
 static bool write_public_keyfile(RSA* private_key, const std::string& private_key_path) {
     uint8_t binary_key_data[ANDROID_PUBKEY_ENCODED_SIZE];
     if (!android_pubkey_encode(private_key, binary_key_data, sizeof(binary_key_data))) {
