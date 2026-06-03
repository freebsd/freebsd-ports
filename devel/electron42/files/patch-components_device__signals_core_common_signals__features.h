--- components/device_signals/core/common/signals_features.h.orig	2026-04-28 21:06:17 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -36,7 +36,7 @@ bool IsPolicyDataCollectionEnabled();
 bool IsPolicyDataCollectionEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
