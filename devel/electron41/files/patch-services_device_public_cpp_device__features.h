--- services/device/public/cpp/device_features.h.orig	2026-03-30 20:35:34 UTC
+++ services/device/public/cpp/device_features.h
@@ -50,7 +50,7 @@ DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermis
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
