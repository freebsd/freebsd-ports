--- services/device/public/cpp/device_features.cc.orig	2025-10-21 20:19:54 UTC
+++ services/device/public/cpp/device_features.cc
@@ -81,7 +81,7 @@ BASE_FEATURE(kBatteryStatusManagerBroadcastReceiverInB
 // Modifies the internal allowlist behavior that enables privileged extensions
 // to bypass the HID blocklist when accessing FIDO devices. When enabled,
 // privileged extensions can access non-FIDO interfaces on known security keys.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSecurityKeyHidInterfacesAreFido,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
@@ -130,7 +130,7 @@ BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLE
 // a USB interface is busy.
 #if BUILDFLAG(IS_ANDROID)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_ENABLED_BY_DEFAULT);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAutomaticUsbDetach, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
