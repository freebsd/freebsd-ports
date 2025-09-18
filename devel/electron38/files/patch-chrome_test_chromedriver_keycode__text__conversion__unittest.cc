--- chrome/test/chromedriver/keycode_text_conversion_unittest.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/test/chromedriver/keycode_text_conversion_unittest.cc
@@ -64,7 +64,7 @@ std::string ConvertKeyCodeToTextNoError(ui::KeyboardCo
 
 }  // namespace
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_KeyCodeToText DISABLED_KeyCodeToText
 #else
@@ -98,7 +98,7 @@ TEST(KeycodeTextConversionTest, MAYBE_KeyCodeToText) {
       ConvertKeyCodeToTextNoError(ui::VKEY_SHIFT, kShiftKeyModifierMask));
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Fails on bots: crbug.com/174962
 #define MAYBE_CharToKeyCode DISABLED_CharToKeyCode
 #else
