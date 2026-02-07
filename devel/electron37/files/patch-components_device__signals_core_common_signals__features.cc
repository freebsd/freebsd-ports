--- components/device_signals/core/common/signals_features.cc.orig	2025-06-30 07:04:30 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -43,7 +43,7 @@ bool IsBrowserSignalsReportingEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
