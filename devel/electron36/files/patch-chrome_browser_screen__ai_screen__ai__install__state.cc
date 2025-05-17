--- chrome/browser/screen_ai/screen_ai_install_state.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/screen_ai/screen_ai_install_state.cc
@@ -30,7 +30,7 @@ bool IsDeviceCompatible() {
   // TODO(crbug.com/381256355): Update when ScreenAI library is compatible with
   // older CPUs.
   static const bool device_compatible = base::CPU().has_sse42();
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, the library is only built for X86 CPUs.
   static constexpr bool device_compatible = false;
 #else
