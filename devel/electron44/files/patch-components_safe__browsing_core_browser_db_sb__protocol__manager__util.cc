--- components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc.orig	2026-08-24 20:59:34 UTC
+++ components/safe_browsing/core/browser/db/sb_protocol_manager_util.cc
@@ -207,7 +207,7 @@ PlatformType GetCurrentPlatformType() {
 PlatformType GetCurrentPlatformType() {
 #if BUILDFLAG(IS_WIN)
   return WINDOWS_PLATFORM;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return LINUX_PLATFORM;
 #elif BUILDFLAG(IS_IOS)
   return IOS_PLATFORM;
