--- content/browser/utility_sandbox_delegate.cc.orig	2022-05-25 04:01:01 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -62,10 +62,10 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_PLUGINS)
       sandbox_type_ == sandbox::mojom::Sandbox::kPpapi ||
 #endif
-#if BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kVideoCapture ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -75,7 +75,7 @@ UtilitySandboxedProcessLauncherDelegate::
       sandbox_type_ == sandbox::mojom::Sandbox::kLibassistant ||
 #endif  // BUILDFLAG(ENABLE_CROS_LIBASSISTANT)
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kAudio ||
@@ -108,7 +108,7 @@ ZygoteHandle UtilitySandboxedProcessLauncherDelegate::
   // unsandboxed zygote and then apply their actual sandboxes in the forked
   // process upon startup.
   if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork ||
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
@@ -122,7 +122,7 @@ ZygoteHandle UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_OOP_PRINTING)
       sandbox_type_ == sandbox::mojom::Sandbox::kPrintBackend ||
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kScreenAI ||
 #endif
       sandbox_type_ == sandbox::mojom::Sandbox::kSpeechRecognition) {
