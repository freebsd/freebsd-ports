--- net/disk_cache/backend_experiment.h.orig	2025-08-26 20:49:50 UTC
+++ net/disk_cache/backend_experiment.h
@@ -15,7 +15,7 @@ constexpr bool IsSimpleBackendEnabledByDefaultPlatform
 // default.
 constexpr bool IsSimpleBackendEnabledByDefaultPlatform() {
   return BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) ||
-         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC);
+         BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD);
 }
 
 // True if assigned to any of disk cache backend experiment groups.
