--- services/on_device_model/on_device_model_service.h.orig	2024-06-18 21:43:38 UTC
+++ services/on_device_model/on_device_model_service.h
@@ -22,6 +22,10 @@
 #include "sandbox/policy/linux/sandbox_linux.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "sandbox/policy/sandbox.h"
+#endif
+
 namespace on_device_model {
 
 class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelService
@@ -35,7 +39,7 @@ class COMPONENT_EXPORT(ON_DEVICE_MODEL) OnDeviceModelS
   // Must be called in the service's process after the run loop finished.
   [[nodiscard]] static bool Shutdown();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   static void AddSandboxLinuxOptions(
       sandbox::policy::SandboxLinux::Options& options);
 #endif
