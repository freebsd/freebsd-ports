--- adb/client/auth.cpp.orig	2019-10-18 00:22:21 UTC
+++ adb/client/auth.cpp
@@ -34,7 +34,10 @@
 #include <android-base/stringprintf.h>
 #include <android-base/strings.h>
 #include <crypto_utils/android_pubkey.h>
+#if defined(OPENSSL_IS_BORINGSSL)
 #include <openssl/base64.h>
+#endif
+#include <openssl/err.h>
 #include <openssl/evp.h>
 #include <openssl/objects.h>
 #include <openssl/pem.h>
@@ -52,6 +55,30 @@ static std::mutex& g_keys_mutex = *new std::mutex;
 static std::map<std::string, std::shared_ptr<RSA>>& g_keys =
     *new std::map<std::string, std::shared_ptr<RSA>>;
 static std::map<int, std::string>& g_monitored_paths = *new std::map<int, std::string>;
+
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
 
 static std::string get_user_info() {
     std::string hostname;
