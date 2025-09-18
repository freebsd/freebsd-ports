--- components/device_signals/core/common/signals_features.h.orig	2025-08-26 20:49:50 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -33,7 +33,7 @@ bool IsDetectedAgentSignalCollectionEnabled();
 bool IsDetectedAgentSignalCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
