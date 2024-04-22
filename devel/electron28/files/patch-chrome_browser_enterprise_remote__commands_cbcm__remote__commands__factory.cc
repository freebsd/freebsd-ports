--- chrome/browser/enterprise/remote_commands/cbcm_remote_commands_factory.cc.orig	2023-11-29 21:39:48 UTC
+++ chrome/browser/enterprise/remote_commands/cbcm_remote_commands_factory.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/profiles/profile_manager.h"
 #include "components/policy/core/common/remote_commands/remote_command_job.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/remote_commands/rotate_attestation_credential_job.h"
 #include "chrome/browser/policy/chrome_browser_policy_connector.h"
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
@@ -30,7 +30,7 @@ CBCMRemoteCommandsFactory::BuildJobForType(
         g_browser_process->profile_manager());
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (type == enterprise_management::
                   RemoteCommand_Type_BROWSER_ROTATE_ATTESTATION_CREDENTIAL) {
     return std::make_unique<RotateAttestationCredentialJob>(
