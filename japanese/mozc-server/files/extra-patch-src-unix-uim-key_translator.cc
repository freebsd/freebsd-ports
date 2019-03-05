--- src/unix/uim/key_translator.cc.orig	2019-03-04 19:32:08.940982000 +0900
+++ src/unix/uim/key_translator.cc	2019-03-04 19:32:33.285357000 +0900
@@ -368,25 +368,25 @@
 
 void KeyTranslator::Init() {
   for (int i = 0; i < arraysize(special_key_map); ++i) {
-    CHECK(special_key_map_.insert(make_pair(special_key_map[i].from,
+    CHECK(special_key_map_.insert(std::make_pair(special_key_map[i].from,
                                             special_key_map[i].to)).second);
   }
   for (int i = 0; i < arraysize(modifier_key_map); ++i) {
-    CHECK(modifier_key_map_.insert(make_pair(modifier_key_map[i].from,
+    CHECK(modifier_key_map_.insert(std::make_pair(modifier_key_map[i].from,
                                              modifier_key_map[i].to)).second);
   }
   for (int i = 0; i < arraysize(modifier_mask_map); ++i) {
-    CHECK(modifier_mask_map_.insert(make_pair(modifier_mask_map[i].from,
+    CHECK(modifier_mask_map_.insert(std::make_pair(modifier_mask_map[i].from,
                                               modifier_mask_map[i].to)).second);
   }
   for (int i = 0; i < arraysize(kana_map_jp); ++i) {
     CHECK(kana_map_jp_.insert(
-        make_pair(kana_map_jp[i].code, make_pair(
+        std::make_pair(kana_map_jp[i].code, std::make_pair(
             kana_map_jp[i].no_shift, kana_map_jp[i].shift))).second);
   }
   for (int i = 0; i < arraysize(kana_map_us); ++i) {
     CHECK(kana_map_us_.insert(
-        make_pair(kana_map_us[i].code, make_pair(
+        std::make_pair(kana_map_us[i].code, std::make_pair(
             kana_map_us[i].no_shift, kana_map_us[i].shift))).second);
   }
 }
