--- electron/atom/app/atom_main_delegate.cc.orig	2019-09-11 17:30:11 UTC
+++ electron/atom/app/atom_main_delegate.cc
@@ -8,7 +8,7 @@
 #include <memory>
 #include <string>
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <glib.h>  // for g_setenv()
 #endif
 
@@ -229,7 +229,7 @@ void AtomMainDelegate::PostEarlyInitialization(bool is
         ui::ResourceBundle::GetSharedInstance().GetLocaleFilePath(locale, true);
     if (!locale_file_path.empty()) {
       custom_locale = locale;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       /* When built with USE_GLIB, libcc's GetApplicationLocaleInternal() uses
        * glib's g_get_language_names(), which keys off of getenv("LC_ALL") */
       g_setenv("LC_ALL", custom_locale.c_str(), TRUE);
