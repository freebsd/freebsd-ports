--- components/device_signals/core/common/signals_features.cc.orig	2025-08-26 20:49:50 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -55,7 +55,7 @@ bool IsDetectedAgentSignalCollectionEnabled() {
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
