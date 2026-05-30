--- chrome/browser/flag_descriptions.h.orig	2026-05-18 23:17:45 UTC
+++ chrome/browser/flag_descriptions.h
@@ -8465,6 +8465,18 @@ inline constexpr char kAndroidEntraSsoDescription[] =
     "Enables native support for Entra SSO on Android provided by selected "
     "Authentication Brokers.";
 
+#if BUILDFLAG(IS_BSD)
+inline constexpr char kAudioBackendName[] =
+    "Audio Backend";
+inline constexpr char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
+
 // ============================================================================
 // Don't just add flags to the end, put them in the alphabetical order.
 // ============================================================================
