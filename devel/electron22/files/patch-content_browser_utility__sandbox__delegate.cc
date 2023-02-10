--- content/browser/utility_sandbox_delegate.cc.orig	2023-01-30 07:58:59 UTC
+++ content/browser/utility_sandbox_delegate.cc
@@ -65,10 +65,10 @@ UtilitySandboxedProcessLauncherDelegate::
 #if BUILDFLAG(ENABLE_PPAPI)
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
@@ -117,7 +117,7 @@ ZygoteHandle UtilitySandboxedProcessLauncherDelegate::
   // unsandboxed zygote and then apply their actual sandboxes in the forked
   // process upon startup.
   if (sandbox_type_ == sandbox::mojom::Sandbox::kNetwork ||
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
       sandbox_type_ == sandbox::mojom::Sandbox::kHardwareVideoDecoding ||
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
 #if BUILDFLAG(IS_CHROMEOS_ASH)
