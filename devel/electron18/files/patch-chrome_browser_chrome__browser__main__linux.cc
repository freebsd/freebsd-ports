--- chrome/browser/chrome_browser_main_linux.cc.orig	2022-05-19 05:17:36 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -57,7 +57,7 @@ ChromeBrowserMainPartsLinux::~ChromeBrowserMainPartsLi
 }
 
 void ChromeBrowserMainPartsLinux::PostCreateMainMessageLoop() {
-#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // No-op: Ash and Lacros Bluetooth DBusManager initialization depend on
   // FeatureList, and is done elsewhere.
 #else
@@ -122,7 +122,7 @@ void ChromeBrowserMainPartsLinux::PostBrowserStart() {
 #endif  // defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
