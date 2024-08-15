--- content/public/common/content_features.cc.orig	2024-06-18 21:43:32 UTC
+++ content/public/common/content_features.cc
@@ -29,7 +29,7 @@ BASE_FEATURE(kAudioServiceOutOfProcess,
 // TODO(crbug.com/40118868): Remove !IS_CHROMEOS_LACROS once lacros starts being
 // built with OS_CHROMEOS instead of OS_LINUX.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -1076,9 +1076,9 @@ BASE_FEATURE(kWebAssemblyTrapHandler,
 BASE_FEATURE(kWebAssemblyTrapHandler,
              "WebAssemblyTrapHandler",
 #if ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) ||  \
-      BUILDFLAG(IS_MAC)) &&                                                  \
+      BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) &&                                                  \
      defined(ARCH_CPU_X86_64)) ||                                            \
-    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)) && \
+    ((BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)) && \
      defined(ARCH_CPU_ARM64))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
@@ -1115,7 +1115,11 @@ BASE_FEATURE(kWebUICodeCache,
 
 // Controls whether the WebUSB API is enabled:
 // https://wicg.github.io/webusb
+#if BUILDFLAG(IS_BSD)
+BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kWebUsb, "WebUSB", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 // Controls whether the WebXR Device API is enabled.
 BASE_FEATURE(kWebXr, "WebXR", base::FEATURE_ENABLED_BY_DEFAULT);
