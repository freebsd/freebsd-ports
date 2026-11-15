--- components/device_signals/core/common/platform_utils.h.orig	2026-10-19 21:50:55 UTC
+++ components/device_signals/core/common/platform_utils.h
@@ -59,7 +59,7 @@ std::optional<std::string> GetWindowsMachineDomain();
 std::optional<std::string> GetWindowsMachineDomain();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Return the distribution VERSION_ID contained in
 // /etc/os-release, if it exists.
 std::optional<std::string> GetDistributionVersion();
