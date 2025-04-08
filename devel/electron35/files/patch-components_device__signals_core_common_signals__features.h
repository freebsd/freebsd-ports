--- components/device_signals/core/common/signals_features.h.orig	2025-03-24 20:50:14 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -14,7 +14,7 @@ BASE_DECLARE_FEATURE(kAllowClientCertificateReportingF
 BASE_DECLARE_FEATURE(kAllowClientCertificateReportingForUsers);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
