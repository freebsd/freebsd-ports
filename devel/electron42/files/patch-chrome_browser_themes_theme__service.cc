--- chrome/browser/themes/theme_service.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -75,7 +75,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/time/time.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_factory.h"
@@ -260,7 +260,7 @@ void ThemeService::RegisterProfilePrefs(
 // static
 void ThemeService::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterIntegerPref(prefs::kSystemTheme,
                                 static_cast<int>(ui::GetDefaultSystemTheme()));
 #endif
@@ -391,7 +391,7 @@ bool ThemeService::ShouldUseCustomFrame() const {
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
