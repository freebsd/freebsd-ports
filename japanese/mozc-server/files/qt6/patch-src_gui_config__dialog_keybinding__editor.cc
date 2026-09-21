--- src/gui/config_dialog/keybinding_editor.cc.orig	2026-09-15 03:56:19 UTC
+++ src/gui/config_dialog/keybinding_editor.cc
@@ -453,7 +453,7 @@ KeyBindingFilter::KeyState KeyBindingFilter::AddKey(
     return Encode(result);
   }
 
-  unknown_key_.sprintf("<UNK:0x%x 0x%x 0x%x>",
+  unknown_key_.asprintf("<UNK:0x%x 0x%x 0x%x>",
                        key_event.key(),
                        key_event.nativeScanCode(),
                        key_event.nativeVirtualKey());
