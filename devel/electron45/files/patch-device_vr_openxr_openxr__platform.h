--- device/vr/openxr/openxr_platform.h.orig	2026-10-19 21:50:55 UTC
+++ device/vr/openxr/openxr_platform.h
@@ -21,7 +21,7 @@
 #elif BUILDFLAG(IS_ANDROID)
 #include <EGL/egl.h>
 #include <jni.h>
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <vulkan/vulkan_core.h>
 #endif
 
