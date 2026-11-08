--- chrome/common/channel_info.h.orig	2025-04-22 20:15:27 UTC
+++ chrome/common/channel_info.h
@@ -11,7 +11,7 @@
 #include "build/branding_buildflags.h"
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 namespace base {
 class Environment;
 }
@@ -99,7 +99,7 @@ std::string GetChannelSuffixForDataDir();
 std::string GetChannelSuffixForDataDir();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName();
 
 // Returns the channel-specific filename of the desktop shortcut used to launch
