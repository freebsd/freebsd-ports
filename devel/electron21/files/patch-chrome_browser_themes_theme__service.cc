--- chrome/browser/themes/theme_service.cc.orig	2022-08-31 12:19:35 UTC
+++ chrome/browser/themes/theme_service.cc
@@ -72,7 +72,7 @@
 #include "extensions/browser/extension_registry_observer.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #include "ui/ozone/public/ozone_platform.h"
 #endif
@@ -314,7 +314,7 @@ CustomThemeSupplier* ThemeService::GetThemeSupplier() 
 }
 
 bool ThemeService::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return profile_->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
@@ -322,7 +322,7 @@ bool ThemeService::ShouldUseSystemTheme() const {
 }
 
 bool ThemeService::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::OzonePlatform::GetInstance()
            ->GetPlatformRuntimeProperties()
            .supports_server_side_window_decorations) {
