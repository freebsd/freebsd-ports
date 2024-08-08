--- components/device_signals/core/common/signals_features.h.orig	2023-08-10 01:48:40 UTC
+++ components/device_signals/core/common/signals_features.h
@@ -28,7 +28,7 @@ enum class NewEvFunction { kFileSystemInfo, kSettings,
 bool IsNewFunctionEnabled(NewEvFunction new_ev_function);
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDeviceSignalsConsentDialog);
 
 // Returns true if device signals consent dialog has been enabled for
