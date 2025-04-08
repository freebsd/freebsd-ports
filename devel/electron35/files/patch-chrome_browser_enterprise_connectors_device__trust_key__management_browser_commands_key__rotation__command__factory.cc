--- chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc.orig	2024-10-16 21:30:58 UTC
+++ chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc
@@ -19,7 +19,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/win_key_rotation_command.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/linux_key_rotation_command.h"
 #elif BUILDFLAG(IS_MAC)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/mac_key_rotation_command.h"
@@ -53,7 +53,7 @@ std::unique_ptr<KeyRotationCommand> KeyRotationCommand
     policy::DeviceManagementService* device_management_service) {
 #if BUILDFLAG(IS_WIN)
   return std::make_unique<WinKeyRotationCommand>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<LinuxKeyRotationCommand>(url_loader_factory);
 #elif BUILDFLAG(IS_MAC)
   if (IsDTCKeyRotationUploadedBySharedAPI()) {
