--- src/gui/config_dialog/keybinding_editor.cc.orig	2026-10-16 12:33:33 UTC
+++ src/gui/config_dialog/keybinding_editor.cc
@@ -111,8 +111,8 @@ constexpr auto kQtKeyModifierNonRequiredTable =
         {Qt::Key_Hiragana_Katakana, "Hiragana"},
         {Qt::Key_Eisu_toggle, "Eisu"},
         {Qt::Key_Zenkaku_Hankaku, "Hankaku/Zenkaku"},
-#ifdef __linux__
-        // On Linux (X / Wayland), Hangul and Hanja are identical with
+#if defined(__linux__) || defined(__FreeBSD__)
+        // On Linux and FreeBSD (X / Wayland), Hangul and Hanja are identical with
         // ImeOn and ImeOff.
         // https://github.com/google/mozc/issues/552
         //
@@ -120,7 +120,7 @@ constexpr auto kQtKeyModifierNonRequiredTable =
         {Qt::Key_Hangul, "ON"},
         // Hanja == Lang2 (USB HID) / ImeOff (Windows) / Eisu (macOS)
         {Qt::Key_Hangul_Hanja, "OFF"},
-#endif  // __linux__
+#endif  // __linux__ || __FreeBSD__
     });
 // LINT.ThenChange(//composer/key_parser_test.cc)
 
@@ -401,7 +401,7 @@ KeyBindingFilter::KeyState KeyBindingFilter::AddKey(co
     return Encode(result);
   }
 
-  unknown_key_.asprintf("<UNK:0x%x 0x%x 0x%x>", key_event.key(),
+  unknown_key_ = QString::asprintf("<UNK:0x%x 0x%x 0x%x>", key_event.key(),
                         key_event.nativeScanCode(),
                         key_event.nativeVirtualKey());
 
