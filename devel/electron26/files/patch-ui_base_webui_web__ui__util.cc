--- ui/base/webui/web_ui_util.cc.orig	2023-05-25 00:42:53 UTC
+++ ui/base/webui/web_ui_util.cc
@@ -39,7 +39,7 @@ namespace {
 constexpr float kMaxScaleFactor = 1000.0f;
 
 std::string GetFontFamilyMd() {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kWebUiSystemFont)) {
     return GetFontFamily();
   }
@@ -219,7 +219,7 @@ std::string GetFontFamily() {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   std::string font_name = ui::ResourceBundle::GetSharedInstance()
                               .GetFont(ui::ResourceBundle::BaseFont)
                               .GetFontName();
