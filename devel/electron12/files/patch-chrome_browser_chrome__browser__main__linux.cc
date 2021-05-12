--- chrome/browser/chrome_browser_main_linux.cc.orig	2021-04-14 01:08:38 UTC
+++ chrome/browser/chrome_browser_main_linux.cc
@@ -82,6 +82,7 @@ void ChromeBrowserMainPartsLinux::PreProfileInit() {
 void ChromeBrowserMainPartsLinux::PostProfileInit() {
   ChromeBrowserMainPartsPosix::PostProfileInit();
 
+#if !defined(OS_BSD)
   bool breakpad_registered;
   if (crash_reporter::IsCrashpadEnabled()) {
     // If we're using crashpad, there's no breakpad and crashpad is always
@@ -99,10 +100,11 @@ void ChromeBrowserMainPartsLinux::PostProfileInit() {
   }
   g_browser_process->metrics_service()->RecordBreakpadRegistration(
       breakpad_registered);
+#endif
 }
 
 void ChromeBrowserMainPartsLinux::PostMainMessageLoopStart() {
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(nullptr /* system_bus */);
 #endif
 
@@ -110,7 +112,7 @@ void ChromeBrowserMainPartsLinux::PostMainMessageLoopS
 }
 
 void ChromeBrowserMainPartsLinux::PostDestroyThreads() {
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   bluez::BluezDBusManager::Shutdown();
   bluez::BluezDBusThreadManager::Shutdown();
 #endif
