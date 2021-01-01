--- chrome/browser/chrome_browser_main_linux.cc.orig	2019-09-10 11:13:38 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -90,12 +90,14 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
 void ChromeBrowserMainPartsLinux::PostProfileInit() {
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
+#if !defined(OS_BSD)
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
       breakpad::IsCrashReporterEnabled());
+#endif
 }
 
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopStart() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
 #endif
 
@@ -103,7 +105,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::BluezDBusThreadManager::Shutdown();
 #endif
