--- remoting/base/chromoting_event.cc.orig	2019-12-12 12:39:54 UTC
+++ remoting/base/chromoting_event.cc
@@ -188,7 +188,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif defined(OS_CHROMEOS)
   Os os = Os::CHROMOTING_CHROMEOS;
