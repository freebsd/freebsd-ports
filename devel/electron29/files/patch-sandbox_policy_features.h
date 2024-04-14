--- sandbox/policy/features.h.orig	2024-02-21 00:20:51 UTC
+++ sandbox/policy/features.h
@@ -44,7 +44,7 @@ SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kForceSpect
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(kForceSpectreVariant2Mitigation);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 SANDBOX_POLICY_EXPORT BASE_DECLARE_FEATURE(
     kForceDisableSpectreVariant2MitigationInNetworkService);
 
