--- content/browser/utility_sandbox_delegate.cc.orig	2025-02-02 01:39:09 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -85,10 +85,10 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(IS_FUCHSIA)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -102,10 +102,10 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_SCREEN_AI_SERVICE)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
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
@@ -168,10 +168,10 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
   // process upon startup.
   if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceModelExecution ||
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoEncoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -189,7 +189,7 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
 #if BUILDFLAG(ENABLE_SCREEN_AI_SERVICE)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoEffects ||
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX)
