--- chrome/common/extensions/command.cc.orig	2019-12-12 12:39:19 UTC
+++ chrome/common/extensions/command.cc
@@ -300,7 +300,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
