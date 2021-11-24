--- chrome/common/extensions/command.cc.orig	2021-04-14 01:08:42 UTC
+++ chrome/common/extensions/command.cc
@@ -294,7 +294,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
