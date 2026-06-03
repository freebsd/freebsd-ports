--- services/device/public/cpp/device_features.cc.orig	2026-04-19 04:41:10 UTC
+++ services/device/public/cpp/device_features.cc
@@ -137,7 +137,7 @@ BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLE
 // a USB interface is busy.
 #if BUILDFLAG(IS_ANDROID)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
