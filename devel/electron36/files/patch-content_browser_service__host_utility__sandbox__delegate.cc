--- content/browser/service_host/utility_sandbox_delegate.cc.orig	2025-05-11 11:50:45 UTC
+++ content/browser/service_host/utility_sandbox_delegate.cc
@@ -79,7 +79,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(IS_FUCHSIA)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -92,14 +92,14 @@ UtilitySandboxedProcessLauncherDelegate::
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -163,7 +163,7 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
   // process upon startup.
   if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceModelExecution ||
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -177,11 +177,11 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
 #endif  // BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX)
