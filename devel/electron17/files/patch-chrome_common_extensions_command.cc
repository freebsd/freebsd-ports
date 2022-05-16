--- chrome/common/extensions/command.cc.orig	2021-10-08 06:25:42 UTC
+++ chrome/common/extensions/command.cc
@@ -294,7 +294,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_CHROMEOS_LACROS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
