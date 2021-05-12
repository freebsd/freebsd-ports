--- chrome/browser/web_applications/components/web_app_shortcut.cc.orig	2021-04-14 01:08:42 UTC
+++ chrome/browser/web_applications/components/web_app_shortcut.cc
@@ -33,7 +33,7 @@ namespace {
 
 #if defined(OS_MAC)
 const int kDesiredIconSizesForShortcut[] = {16, 32, 128, 256, 512};
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Linux supports icons of any size. FreeDesktop Icon Theme Specification states
 // that "Minimally you should install a 48x48 icon in the hicolor theme."
 const int kDesiredIconSizesForShortcut[] = {16, 32, 48, 128, 256, 512};
