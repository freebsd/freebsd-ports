--- content/public/common/content_features.cc.orig	2026-04-28 21:06:17 UTC
+++ content/public/common/content_features.cc
@@ -140,7 +140,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
 
 // Runs the audio service in a separate process.
 BASE_FEATURE(kAudioServiceOutOfProcess,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -150,7 +150,7 @@ BASE_FEATURE(kAudioServiceSandbox,
 // Enables the audio-service sandbox. This feature has an effect only when the
 // kAudioServiceOutOfProcess feature is enabled.
 BASE_FEATURE(kAudioServiceSandbox,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1152,10 +1152,10 @@ BASE_FEATURE(kWebAssemblyTrapHandler,
 
 // Enable WebAssembly trap handler.
 BASE_FEATURE(kWebAssemblyTrapHandler,
-#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
+#if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
       BUILDFLAG(IS_MAC)) &&                                                  \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1216,7 +1216,11 @@ BASE_FEATURE(kWebUIInProcessResourceLoadingV2,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Apply `PrefetchPriority::kHighest` for Webview Prefetch API.
 BASE_FEATURE(kWebViewPrefetchHighestPrefetchPriority,
