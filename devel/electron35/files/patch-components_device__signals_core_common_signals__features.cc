--- components/device_signals/core/common/signals_features.cc.orig	2025-03-24 20:50:14 UTC
+++ components/device_signals/core/common/signals_features.cc
@@ -11,7 +11,7 @@ BASE_FEATURE(kAllowClientCertificateReportingForUsers,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the triggering of device signals consent dialog when conditions met
 // This feature also requires UnmanagedDeviceSignalsConsentFlowEnabled policy to
 // be enabled
