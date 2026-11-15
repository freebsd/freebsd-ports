--- ui/base/webui/web_ui_util.cc.orig	2026-10-19 21:50:55 UTC
+++ ui/base/webui/web_ui_util.cc
@@ -44,7 +44,7 @@ std::string GetFontFamilyMd() {
 constexpr float kMaxScaleFactor = 1000.0f;
 
 std::string GetFontFamilyMd() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Roboto, " + GetFontFamily();
 #else
   return GetFontFamily();
@@ -239,7 +239,7 @@ std::string GetFontFamily() {
 std::string GetFontFamily() {
   std::string font_family = l10n_util::GetStringUTF8(IDS_WEB_FONT_FAMILY);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string font_name = ui::ResourceBundle::GetSharedInstance()
                               .GetFont(ui::ResourceBundle::BaseFont)
                               .GetFontName();
