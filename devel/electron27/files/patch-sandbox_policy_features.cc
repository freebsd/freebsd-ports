--- sandbox/policy/features.cc.orig	2023-10-19 19:58:30 UTC
+++ sandbox/policy/features.cc
@@ -19,7 +19,11 @@ namespace sandbox::policy::features {
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
