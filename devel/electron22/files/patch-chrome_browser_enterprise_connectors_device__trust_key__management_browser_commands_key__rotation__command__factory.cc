--- chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc.orig	2022-10-24 13:33:33 UTC
+++ chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc
@@ -14,7 +14,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/win_key_rotation_command.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/linux_key_rotation_command.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/mac_key_rotation_command.h"
@@ -47,7 +47,7 @@ std::unique_ptr<KeyRotationCommand> KeyRotationCommand
     PrefService* local_prefs) {
 #if BUILDFLAG(IS_WIN)
   return std::make_unique<WinKeyRotationCommand>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<LinuxKeyRotationCommand>(url_loader_factory);
 #elif BUILDFLAG(IS_MAC)
   return std::make_unique<MacKeyRotationCommand>(url_loader_factory,
