--- sandbox/policy/features.cc.orig	2023-11-29 21:40:08 UTC
+++ sandbox/policy/features.cc
@@ -19,7 +19,11 @@ BASE_FEATURE(kNetworkServiceSandbox,
 // (Only causes an effect when feature kNetworkServiceInProcess is disabled.)
 BASE_FEATURE(kNetworkServiceSandbox,
              "NetworkServiceSandbox",
+#if BUILDFLAG(IS_BSD)
+             base::FEATURE_ENABLED_BY_DEFAULT);
+#else
              base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 // Enables a fine-grained seccomp-BPF syscall filter for the network service.
@@ -126,7 +130,7 @@ BASE_FEATURE(kForceSpectreVariant2Mitigation,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enabling the kNetworkServiceSandbox feature automatically enables Spectre
 // variant 2 mitigations in the network service. This can lead to performance
 // regressions, so enabling this feature will turn off the Spectre Variant 2
