--- src/unix/uim/key_translator.h.orig	2021-05-12 03:17:52 UTC
+++ src/unix/uim/key_translator.h
@@ -38,8 +38,13 @@ using __gnu_cxx::hash_map;
 using __gnu_cxx::hash_map;
 
 #include "base/port.h"
+#include "base/vlog.h"
 #include "protocol/commands.pb.h"
 
+using std::string;
+typedef uint64_t uint64;
+typedef int32_t int32;
+
 namespace mozc {
 namespace uim {
 
@@ -49,6 +54,8 @@ class KeyTranslator {
 class KeyTranslator {
  public:
   KeyTranslator();
+  KeyTranslator(const KeyTranslator&) = delete;
+  KeyTranslator& operator=(const KeyTranslator&) = delete;
   virtual ~KeyTranslator();
 
   // Converts ibus keycode to Mozc key code and stores them on |out_event|.
@@ -101,8 +108,6 @@ class KeyTranslator {
   // 'Hiragana Letter Small U' (with Shift modifier).
   KanaMap kana_map_jp_;  // mapping for JP keyboard.
   KanaMap kana_map_us_;  // mapping for US keyboard.
-
-  DISALLOW_COPY_AND_ASSIGN(KeyTranslator);
 };
 
 }  // namespace uim
