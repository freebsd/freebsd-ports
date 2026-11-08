--- src/unix/uim/key_translator.cc.orig	2021-05-12 03:17:52 UTC
+++ src/unix/uim/key_translator.cc
@@ -32,7 +32,9 @@
 
 #include <uim.h>
 
-#include "base/logging.h"
+#include "absl/log/log.h"
+#include "absl/log/check.h"
+#include "base/log_file.h"
 
 namespace {
 
@@ -344,7 +346,7 @@ bool KeyTranslator::Translate(unsigned int keyval,
     /* regards yen key as backslash */
     out_event->set_key_code('\\');
   } else {
-    VLOG(1) << "Unknown keyval: " << keyval;
+    MOZC_VLOG(1) << "Unknown keyval: " << keyval;
     return false;
   }
 
@@ -367,28 +369,28 @@ void KeyTranslator::Init() {
 }
 
 void KeyTranslator::Init() {
-  for (int i = 0; i < arraysize(special_key_map); ++i) {
+  for (int i = 0; i < std::size(special_key_map); ++i) {
     CHECK(special_key_map_.insert(
         std::make_pair(special_key_map[i].from,
                        special_key_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(modifier_key_map); ++i) {
+  for (int i = 0; i < std::size(modifier_key_map); ++i) {
     CHECK(modifier_key_map_.insert(
         std::make_pair(modifier_key_map[i].from,
                        modifier_key_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(modifier_mask_map); ++i) {
+  for (int i = 0; i < std::size(modifier_mask_map); ++i) {
     CHECK(modifier_mask_map_.insert(
         std::make_pair(modifier_mask_map[i].from,
                        modifier_mask_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(kana_map_jp); ++i) {
+  for (int i = 0; i < std::size(kana_map_jp); ++i) {
     CHECK(kana_map_jp_.insert(
         std::make_pair(kana_map_jp[i].code,
                        std::make_pair(kana_map_jp[i].no_shift,    
                                       kana_map_jp[i].shift))).second);
   }
-  for (int i = 0; i < arraysize(kana_map_us); ++i) {
+  for (int i = 0; i < std::size(kana_map_us); ++i) {
     CHECK(kana_map_us_.insert(
         std::make_pair(kana_map_us[i].code,
                        std::make_pair(kana_map_us[i].no_shift,
