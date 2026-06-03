--- chrome/browser/renderer_preferences_util.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/renderer_preferences_util.cc
@@ -40,7 +40,7 @@
 #include "ui/views/controls/textfield/textfield.h"
 #endif
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "chrome/browser/themes/theme_service.h"
 #include "chrome/browser/themes/theme_service_factory.h"
 #include "ui/linux/linux_ui.h"
@@ -185,7 +185,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
   prefs->caret_blink_interval = views::Textfield::GetCaretBlinkInterval();
 #endif
 
-#if defined(USE_AURA) && BUILDFLAG(IS_LINUX)
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   auto* linux_ui_theme = ui::LinuxUiTheme::GetForProfile(profile);
   if (linux_ui_theme) {
     if (ThemeServiceFactory::GetForProfile(profile)->UsingSystemTheme()) {
@@ -208,7 +208,7 @@ void UpdateFromSystemSettings(blink::RendererPreferenc
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   content::UpdateFontRendererPreferencesFromSystemSettings(prefs);
 #endif
 
