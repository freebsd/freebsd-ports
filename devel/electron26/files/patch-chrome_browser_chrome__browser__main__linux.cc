--- chrome/browser/chrome_browser_main_linux.cc.orig	2023-08-10 01:48:34 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -53,13 +53,15 @@ ChromeBrowserMainPartsLinux::~ChromeBrowserMainPartsLi
 }
 
 void ChromeBrowserMainPartsLinux::PostCreateMainMessageLoop() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op: Ash and Lacros Bluetooth DBusManager initialization depend on
   // FeatureList, and is done elsewhere.
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
+#endif
 
   // Set up crypt config. This needs to be done before anything starts the
   // network service, as the raw encryption key needs to be shared with the
@@ -117,7 +119,7 @@ void ChromeBrowserMainPartsLinux::PostBrowserStart() {
 #endif  // defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS)
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // No-op; per PostBrowserStart() comment, this is done elsewhere.
 #else
   bluez::BluezDBusManager::Shutdown();
