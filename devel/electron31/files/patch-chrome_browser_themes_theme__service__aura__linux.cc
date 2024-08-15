--- chrome/browser/themes/theme_service_aura_linux.cc.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/themes/theme_service_aura_linux.cc
@@ -24,7 +24,7 @@ namespace {
 ui::SystemTheme ValidateSystemTheme(ui::SystemTheme system_theme) {
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
     case ui::SystemTheme::kQt:
 #endif
