--- remoting/base/chromoting_event.cc.orig	2021-04-14 01:08:53 UTC
+++ remoting/base/chromoting_event.cc
@@ -189,7 +189,7 @@ void ChromotingEvent::AddSystemInfo() {
   SetString(kCpuKey, base::SysInfo::OperatingSystemArchitecture());
   SetString(kOsVersionKey, base::SysInfo::OperatingSystemVersion());
   SetString(kWebAppVersionKey, STRINGIZE(VERSION));
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   Os os = Os::CHROMOTING_LINUX;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   Os os = Os::CHROMOTING_CHROMEOS;
