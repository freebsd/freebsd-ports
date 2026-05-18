--- components/device_signals/core/common/signals_features.cc.orig	2026-04-28 21:06:17 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -54,7 +54,7 @@ bool IsPolicyDataCollectionEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
