--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2019-03-15 06:37:03 UTC
+++ chrome/browser/extensions/bookmark_app_helper.cc
@@ -784,7 +784,7 @@ void BookmarkAppHelper::FinishInstallation(const Exten
 #if !defined(OS_MACOSX)
 #if !defined(OS_CHROMEOS)
   web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   creation_locations.on_desktop = true;
 #else
   creation_locations.on_desktop = false;
