--- components/device_signals/core/browser/desktop/desktop_os_signals_collector.cc.orig	2025-08-26 20:49:50 UTC
+++ components/device_signals/core/browser/desktop/desktop_os_signals_collector.cc
@@ -43,7 +43,7 @@ std::unique_ptr<OsSignalsResponse> AddAsyncOsSignals(
     os_signals_response->disk_encryption = device_signals::GetDiskEncrypted();
     os_signals_response->os_firewall = device_signals::GetOSFirewall();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     os_signals_response->distribution_version =
         device_signals::GetDistributionVersion();
 #endif  // BUILDFLAG(IS_LINUX)
