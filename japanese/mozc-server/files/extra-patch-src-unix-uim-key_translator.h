--- src/unix/uim/key_translator.h.orig	2015-07-15 10:04:31.000000000 +0900
+++ src/unix/uim/key_translator.h	2019-03-04 19:28:03.722916000 +0900
@@ -62,8 +62,8 @@
 
  private:
   typedef hash_map<unsigned int, commands::KeyEvent::SpecialKey> SpecialKeyMap;
-  typedef map<unsigned int, commands::KeyEvent::ModifierKey> ModifierKeyMap;
-  typedef map<unsigned int, pair<string, string> > KanaMap;
+  typedef std::map<unsigned int, commands::KeyEvent::ModifierKey> ModifierKeyMap;
+  typedef std::map<unsigned int, std::pair<string, string> > KanaMap;
 
   // Returns true iff key is modifier key such as SHIFT, ALT, or CAPSLOCK.
   bool IsModifierKey(unsigned int keyval,
