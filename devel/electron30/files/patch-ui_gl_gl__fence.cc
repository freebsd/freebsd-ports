--- ui/gl/gl_fence.cc.orig	2023-10-19 19:59:21 UTC
+++ ui/gl/gl_fence.cc
@@ -20,7 +20,7 @@
 #endif
 
 #if defined(USE_EGL)
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #define USE_GL_FENCE_ANDROID_NATIVE_FENCE_SYNC
 #include "ui/gl/gl_fence_android_native_fence_sync.h"
 #endif
