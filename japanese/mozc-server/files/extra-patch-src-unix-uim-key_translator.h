--- src/unix/uim/key_translator.h.orig
+++ src/unix/uim/key_translator.h
@@ -34,11 +34,12 @@
 #include <uim.h>
 
 #include <map>
-#include <ext/hash_map>
-using __gnu_cxx::hash_map;
+#include <string>
+#include <unordered_map>
+#include <utility>
 
-#include "base/port.h"
 #include "protocol/commands.pb.h"
+#include "protocol/config.pb.h"
 
 namespace mozc {
 namespace uim {
@@ -49,6 +50,8 @@
 class KeyTranslator {
  public:
   KeyTranslator();
+  KeyTranslator(const KeyTranslator&) = delete;
+  KeyTranslator& operator=(const KeyTranslator&) = delete;
   virtual ~KeyTranslator();
 
   // Converts ibus keycode to Mozc key code and stores them on |out_event|.
@@ -61,9 +64,9 @@
                  commands::KeyEvent *out_event) const;
 
  private:
-  typedef hash_map<unsigned int, commands::KeyEvent::SpecialKey> SpecialKeyMap;
+  typedef std::unordered_map<unsigned int, commands::KeyEvent::SpecialKey> SpecialKeyMap;
   typedef std::map<unsigned int, commands::KeyEvent::ModifierKey> ModifierKeyMap;
-  typedef std::map<unsigned int, std::pair<string, string> > KanaMap;
+  typedef std::map<unsigned int, std::pair<std::string, std::string> > KanaMap;
 
   // Returns true iff key is modifier key such as SHIFT, ALT, or CAPSLOCK.
   bool IsModifierKey(unsigned int keyval,
@@ -79,7 +82,7 @@
                        unsigned int keycode,
                        unsigned int modifiers,
                        bool layout_is_jp,
-                       string *out) const;
+                       std::string *out) const;
 
 
   // Returns true iff key is ASCII such as '0', 'A', or '!'.
@@ -101,8 +104,6 @@
   // 'Hiragana Letter Small U' (with Shift modifier).
   KanaMap kana_map_jp_;  // mapping for JP keyboard.
   KanaMap kana_map_us_;  // mapping for US keyboard.
-
-  DISALLOW_COPY_AND_ASSIGN(KeyTranslator);
 };
 
 }  // namespace uim
