--- content/browser/service_host/utility_sandbox_delegate.cc.orig	2026-10-30 11:54:04 UTC
+++ content/browser/service_host/utility_sandbox_delegate.cc
@@ -24,7 +24,7 @@
 #include "sandbox/policy/sandbox_type.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "media/gpu/buildflags.h"
 #include "media/media_buildflags.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
@@ -55,7 +55,7 @@ UtilitySandboxedProcessLauncherDelegate::
 #if DCHECK_IS_ON()
   bool supported_sandbox_type =
       sandbox_type_ == sandbox::mojom::Sandbox::kNoSandbox ||
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kXrCompositing ||
 #endif
 #if BUILDFLAG(IS_WIN)
@@ -79,10 +79,10 @@ UtilitySandboxedProcessLauncherDelegate::
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceModelExecution ||
       sandbox_type_ == sandbox::mojom::Sandbox::kCdm ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintCompositor ||
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #if BUILDFLAG(ENABLE_OOP_VIDEO_DECODER)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
@@ -97,12 +97,12 @@ UtilitySandboxedProcessLauncherDelegate::
       sandbox_type_ == sandbox::mojom::Sandbox::kNearby ||
 #endif  // BUILDFLAG(IS_CHROMEOS)
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPlatformRuntime ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -178,22 +178,22 @@ ZygoteCommunication* UtilitySandboxedProcessLauncherDe
       sandbox_type_ == sandbox::mojom::Sandbox::kNearby ||
 #endif  // BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       // The XR Device Service installs its broker and seccomp policy from a
       // pre-sandbox hook, so it must fork from the unsandboxed zygote (like the
       // other hook-based types) rather than the pre-sandboxed generic zygote.
       sandbox_type_ == sandbox::mojom::Sandbox::kXrCompositing ||
 #endif
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kShapeDetection ||
 #endif
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
       sandbox_type_ == sandbox::mojom::Sandbox::kPlatformRuntime ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kOnDeviceTranslation ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
       sandbox_type_ == sandbox::mojom::Sandbox::kSpeechRecognition) {
