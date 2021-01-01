--- chrome/common/extensions/command.cc.orig	2019-04-08 08:32:47 UTC
+++ chrome/common/extensions/command.cc
@@ -309,7 +309,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
