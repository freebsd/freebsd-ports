--- chrome/common/channel_info_posix.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/common/channel_info_posix.cc
@@ -95,7 +95,7 @@ std::string GetChannelSuffixForDataDir() {
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   const auto channel_state = GetChannelImpl();
@@ -121,7 +121,7 @@ std::string GetChannelSuffixForExtraFlagsEnvVarName() 
 }
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
