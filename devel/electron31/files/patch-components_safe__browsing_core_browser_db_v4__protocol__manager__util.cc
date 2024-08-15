--- components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc.orig	2024-06-18 21:43:30 UTC
+++ components/safe_browsing/core/browser/db/v4_protocol_manager_util.cc
@@ -118,7 +118,7 @@ PlatformType GetCurrentPlatformType() {
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
