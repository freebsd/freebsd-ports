--- chrome/browser/chrome_browser_main_linux.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -88,12 +88,14 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
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
   bluez::DBusThreadManagerLinux::Initialize();
   bluez::BluezDBusManager::Initialize(
       bluez::DBusThreadManagerLinux::Get()->GetSystemBus(), false);
@@ -103,7 +105,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::DBusThreadManagerLinux::Shutdown();
 #endif
