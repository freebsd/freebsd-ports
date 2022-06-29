--- chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/key_rotation_command_factory.cc
@@ -13,7 +13,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/win_key_rotation_command.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/connectors/device_trust/key_management/browser/commands/linux_key_rotation_command.h"
 #endif  // BUILDFLAG(IS_WIN)
 
@@ -43,7 +43,7 @@ std::unique_ptr<KeyRotationCommand> KeyRotationCommand
     scoped_refptr<network::SharedURLLoaderFactory> url_loader_factory) {
 #if BUILDFLAG(IS_WIN)
   return std::make_unique<WinKeyRotationCommand>();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return std::make_unique<LinuxKeyRotationCommand>(
       std::move(url_loader_factory));
 #else
