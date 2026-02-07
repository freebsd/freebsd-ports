--- services/device/public/cpp/device_features.h.orig	2025-04-22 20:15:27 UTC
+++ services/device/public/cpp/device_features.h
@@ -53,7 +53,7 @@ DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermis
 
 DEVICE_FEATURES_EXPORT bool IsOsLevelGeolocationPermissionSupportEnabled();
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 DEVICE_FEATURES_EXPORT BASE_DECLARE_FEATURE(kAutomaticUsbDetach);
 #endif  // BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
 
