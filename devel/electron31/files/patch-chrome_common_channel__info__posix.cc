--- chrome/common/channel_info_posix.cc.orig	2024-06-18 21:43:25 UTC
+++ chrome/common/channel_info_posix.cc
@@ -93,7 +93,7 @@ std::string GetChannelSuffixForDataDir() {
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetChannelSuffixForExtraFlagsEnvVarName() {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   const auto channel_state = GetChannelImpl();
@@ -121,7 +121,7 @@ std::string GetChannelSuffixForExtraFlagsEnvVarName() 
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
 std::string GetDesktopName(base::Environment* env) {
 #if BUILDFLAG(GOOGLE_CHROME_BRANDING)
   // Google Chrome packaged as a snap is a special case: the application name
