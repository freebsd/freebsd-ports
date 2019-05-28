--- electron/brightray/browser/browser_main_parts.cc.orig	2019-03-16 13:00:11 UTC
+++ electron/brightray/browser/browser_main_parts.cc
@@ -12,7 +12,7 @@
 #include <string>
 #include <utility>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib.h>  // for g_setenv()
 #endif
 
@@ -169,7 +169,7 @@ BrowserMainParts::BrowserMainParts() {}
 
 BrowserMainParts::~BrowserMainParts() {}
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 void OverrideAppLogsPath() {
   base::FilePath path;
   if (base::PathService::Get(brightray::DIR_APP_DATA, &path)) {
@@ -256,7 +256,7 @@ void BrowserMainParts::PreMainMessageLoopStart() {
         ui::ResourceBundle::GetSharedInstance().GetLocaleFilePath(locale, true);
     if (!locale_file_path.empty()) {
       custom_locale_ = locale;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       /* When built with USE_GLIB, libcc's GetApplicationLocaleInternal() uses
        * glib's g_get_language_names(), which keys off of getenv("LC_ALL") */
       g_setenv("LC_ALL", custom_locale_.c_str(), TRUE);
