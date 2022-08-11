--- chrome/browser/ui/web_applications/app_browser_controller.cc.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/web_applications/app_browser_controller.cc
@@ -385,7 +385,7 @@ CustomThemeSupplier* AppBrowserController::GetThemeSup
 }
 
 bool AppBrowserController::ShouldUseSystemTheme() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(prefs::kUsesSystemTheme);
 #else
   return false;
@@ -393,7 +393,7 @@ bool AppBrowserController::ShouldUseSystemTheme() cons
 }
 
 bool AppBrowserController::ShouldUseCustomFrame() const {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return browser_->profile()->GetPrefs()->GetBoolean(
       prefs::kUseCustomChromeFrame);
 #else
