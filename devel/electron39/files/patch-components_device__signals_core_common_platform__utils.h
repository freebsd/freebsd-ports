--- components/device_signals/core/common/platform_utils.h.orig	2025-10-21 20:19:54 UTC
+++ components/device_signals/core/common/platform_utils.h
@@ -54,7 +54,7 @@ std::optional<std::string> GetWindowsMachineDomain();
 std::optional<std::string> GetWindowsMachineDomain();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Return the distribution VERSION_ID contained in
 // /etc/os-release, if it exists.
 std::optional<std::string> GetDistributionVersion();
