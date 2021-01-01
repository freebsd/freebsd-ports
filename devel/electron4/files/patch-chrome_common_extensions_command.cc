--- chrome/common/extensions/command.cc.orig	2019-03-15 06:37:09 UTC
+++ chrome/common/extensions/command.cc
@@ -311,7 +311,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
