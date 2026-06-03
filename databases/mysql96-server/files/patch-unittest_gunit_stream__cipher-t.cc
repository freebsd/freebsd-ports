--- unittest/gunit/stream_cipher-t.cc.orig	2024-07-12 19:20:22 UTC
+++ unittest/gunit/stream_cipher-t.cc
@@ -251,10 +251,10 @@ void SetKeyStr(Key_string &key_str, const unsigned cha
 template <typename T>
 void SetKeyStr(Key_string &key_str, const unsigned char *key) {
   if (key) {
-    key_str.assign(key, T::PASSWORD_LENGTH);
+    key_str.assign(key, key + T::PASSWORD_LENGTH);
   } else {
     const unsigned char new_key[T::PASSWORD_LENGTH]{0};
-    key_str.assign(new_key, T::PASSWORD_LENGTH);
+    key_str.assign(new_key, new_key + T::PASSWORD_LENGTH);
   }
 }
 
