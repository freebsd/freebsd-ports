--- remoting/host/host_details.cc.orig	2025-03-24 20:50:14 UTC
+++ remoting/host/host_details.cc
@@ -7,7 +7,7 @@
 #include "base/system/sys_info.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/linux_util.h"
 #endif
 
@@ -22,7 +22,7 @@ std::string GetHostOperatingSystemName() {
   return "Mac";
 #elif BUILDFLAG(IS_CHROMEOS)
   return "ChromeOS";
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return "Linux";
 #elif BUILDFLAG(IS_ANDROID)
   return "Android";
@@ -34,7 +34,7 @@ std::string GetHostOperatingSystemVersion() {
 // Get the host Operating System Version, removing the need to check for OS
 // definitions and keeps the format used consistent.
 std::string GetHostOperatingSystemVersion() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return base::GetLinuxDistro();
 #else
   return base::SysInfo::OperatingSystemVersion();
