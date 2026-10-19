--- src/unix/uim/key_translator.cc.orig
+++ src/unix/uim/key_translator.cc
@@ -32,7 +32,13 @@
 
 #include <uim.h>
 
-#include "base/logging.h"
+#include <cstddef>
+#include <iterator>
+#include <string>
+#include <utility>
+
+#include "absl/log/check.h"
+#include "base/vlog.h"
 
 namespace {
 
@@ -325,7 +331,7 @@
   DCHECK(out_event) << "out_event is NULL";
   out_event->Clear();
 
-  string kana_key_string;
+  std::string kana_key_string;
   if ((method == config::Config::KANA) && IsKanaAvailable(
           keyval, keycode, modifiers, layout_is_jp, &kana_key_string)) {
     out_event->set_key_code(keyval);
@@ -344,7 +350,7 @@
     /* regards yen key as backslash */
     out_event->set_key_code('\\');
   } else {
-    VLOG(1) << "Unknown keyval: " << keyval;
+    MOZC_VLOG(1) << "Unknown keyval: " << keyval;
     return false;
   }
 
@@ -367,28 +373,28 @@
 }
 
 void KeyTranslator::Init() {
-  for (int i = 0; i < arraysize(special_key_map); ++i) {
+  for (std::size_t i = 0; i < std::size(special_key_map); ++i) {
     CHECK(special_key_map_.insert(
         std::make_pair(special_key_map[i].from,
                        special_key_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(modifier_key_map); ++i) {
+  for (std::size_t i = 0; i < std::size(modifier_key_map); ++i) {
     CHECK(modifier_key_map_.insert(
         std::make_pair(modifier_key_map[i].from,
                        modifier_key_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(modifier_mask_map); ++i) {
+  for (std::size_t i = 0; i < std::size(modifier_mask_map); ++i) {
     CHECK(modifier_mask_map_.insert(
         std::make_pair(modifier_mask_map[i].from,
                        modifier_mask_map[i].to)).second);
   }
-  for (int i = 0; i < arraysize(kana_map_jp); ++i) {
+  for (std::size_t i = 0; i < std::size(kana_map_jp); ++i) {
     CHECK(kana_map_jp_.insert(
         std::make_pair(kana_map_jp[i].code,
                        std::make_pair(kana_map_jp[i].no_shift,    
                                       kana_map_jp[i].shift))).second);
   }
-  for (int i = 0; i < arraysize(kana_map_us); ++i) {
+  for (std::size_t i = 0; i < std::size(kana_map_us); ++i) {
     CHECK(kana_map_us_.insert(
         std::make_pair(kana_map_us[i].code,
                        std::make_pair(kana_map_us[i].no_shift,
@@ -412,7 +418,7 @@
                                     unsigned int keycode,
                                     unsigned int modifiers,
                                     bool layout_is_jp,
-                                    string *out) const {
+                                    std::string *out) const {
   if ((modifiers & UMod_Control) || (modifiers & UMod_Alt)) {
     return false;
   }
