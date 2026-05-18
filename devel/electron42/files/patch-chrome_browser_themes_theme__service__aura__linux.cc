--- chrome/browser/themes/theme_service_aura_linux.cc.orig	2024-08-14 20:54:38 UTC
+++ chrome/browser/themes/theme_service_aura_linux.cc
@@ -23,7 +23,7 @@ ui::SystemTheme ValidateSystemTheme(ui::SystemTheme sy
 ui::SystemTheme ValidateSystemTheme(ui::SystemTheme system_theme) {
   switch (system_theme) {
     case ui::SystemTheme::kDefault:
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     case ui::SystemTheme::kGtk:
     case ui::SystemTheme::kQt:
 #endif
