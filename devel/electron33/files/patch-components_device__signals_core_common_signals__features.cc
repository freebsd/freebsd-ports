--- components/device_signals/core/common/signals_features.cc.orig	2023-08-10 01:48:40 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -46,7 +46,7 @@ bool IsNewFunctionEnabled(NewEvFunction new_ev_functio
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
