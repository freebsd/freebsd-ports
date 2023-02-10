--- ui/gl/gl_switches.cc.orig	2022-11-30 08:12:58 UTC
+++ ui/gl/gl_switches.cc
@@ -11,7 +11,7 @@
 #include "base/android/build_info.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <vulkan/vulkan_core.h>
 #include "third_party/angle/src/gpu_info_util/SystemInfo.h"  // nogncheck
 #endif
@@ -282,7 +282,7 @@ bool IsDefaultANGLEVulkan() {
       base::android::SDK_VERSION_Q)
     return false;
 #endif  // BUILDFLAG(IS_ANDROID)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   angle::SystemInfo system_info;
   if (!angle::GetSystemInfoVulkan(&system_info))
     return false;
