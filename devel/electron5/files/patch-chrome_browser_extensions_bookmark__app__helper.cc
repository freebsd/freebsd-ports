--- chrome/browser/extensions/bookmark_app_helper.cc.orig	2019-04-08 08:32:44 UTC
+++ chrome/browser/extensions/bookmark_app_helper.cc
@@ -503,7 +503,7 @@ void BookmarkAppHelper::FinishInstallation(const Exten
   if (create_shortcuts_) {
 #if !defined(OS_CHROMEOS)
     web_app::ShortcutLocations creation_locations;
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     creation_locations.on_desktop = true;
 #else
     creation_locations.on_desktop = false;
