--- components/device_signals/core/browser/browser_utils.h.orig	2025-06-30 07:04:30 UTC
+++ components/device_signals/core/browser/browser_utils.h
@@ -36,7 +36,7 @@ std::string GetHostName();
 // Returns the hostname of the current machine.
 std::string GetHostName();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the hostname of the current machine.
 std::vector<std::string> GetSystemDnsServers();
 
@@ -44,7 +44,7 @@ SettingValue GetOSFirewall();
 SettingValue GetOSFirewall();
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Returns the path to the ufw configuration file.
 const char** GetUfwConfigPath();
 #endif  // BUILDFLAG(IS_LINUX)
