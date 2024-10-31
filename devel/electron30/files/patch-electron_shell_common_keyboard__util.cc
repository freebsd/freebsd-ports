--- electron/shell/common/keyboard_util.cc.orig	2024-09-10 16:10:30 UTC
+++ electron/shell/common/keyboard_util.cc
@@ -16,7 +16,7 @@ using CodeAndShiftedChar = std::pair<ui::KeyboardCode,
 
 using CodeAndShiftedChar = std::pair<ui::KeyboardCode, std::optional<char16_t>>;
 
-constexpr CodeAndShiftedChar KeyboardCodeFromKeyIdentifier(
+CodeAndShiftedChar KeyboardCodeFromKeyIdentifier(
     const std::string_view str) {
 #if BUILDFLAG(IS_MAC)
   constexpr auto CommandOrControl = ui::VKEY_COMMAND;
