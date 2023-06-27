--- chrome/browser/policy/policy_value_and_status_aggregator.cc.orig	2023-05-25 00:41:43 UTC
+++ chrome/browser/policy/policy_value_and_status_aggregator.cc
@@ -55,7 +55,7 @@
 #include "chrome/browser/policy/value_provider/extension_policies_value_provider.h"
 #endif  // BUILDFLAG(ENABLE_EXTENSIONS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/policy/core/common/cloud/profile_cloud_policy_manager.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -106,7 +106,7 @@ std::unique_ptr<policy::PolicyStatusProvider> GetUserP
 #else  // BUILDFLAG(IS_CHROMEOS_ASH)
   policy::CloudPolicyManager* cloud_policy_manager =
       profile->GetUserCloudPolicyManager();
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!cloud_policy_manager) {
     cloud_policy_manager = profile->GetProfileCloudPolicyManager();
   }
