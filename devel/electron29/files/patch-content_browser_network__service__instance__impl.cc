--- content/browser/network_service_instance_impl.cc.orig	2024-02-21 00:20:44 UTC
+++ content/browser/network_service_instance_impl.cc
@@ -81,7 +81,7 @@
 #include "content/browser/network/network_service_process_tracker_win.h"
 #endif
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/browser/system_dns_resolution/system_dns_resolver.h"
 #include "services/network/public/mojom/system_dns_resolution.mojom-forward.h"
 #endif
@@ -359,7 +359,7 @@ void CreateInProcessNetworkService(
                                 std::move(receiver)));
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Runs a self-owned SystemDnsResolverMojoImpl. This is meant to run on a
 // high-priority thread pool.
 void RunSystemDnsResolverOnThreadPool(
@@ -428,7 +428,7 @@ network::mojom::NetworkServiceParamsPtr CreateNetworkS
   }
 #endif  // BUILDFLAG(IS_POSIX)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (GetContentClient()
           ->browser()
           ->ShouldRunOutOfProcessSystemDnsResolution() &&
