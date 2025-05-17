--- components/device_signals/core/common/signals_features.h.orig	2025-04-22 20:15:27 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -24,7 +24,7 @@ bool IsBrowserSignalsReportingEnabled();
 bool IsBrowserSignalsReportingEnabled();
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
