--- third_party/angle/src/libANGLE/Display.cpp.orig	2022-09-24 10:57:32 UTC
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -54,7 +54,7 @@
 #        include "libANGLE/renderer/gl/wgl/DisplayWGL.h"
 #    elif defined(ANGLE_PLATFORM_MACOS) || defined(ANGLE_PLATFORM_IOS)
 #        include "libANGLE/renderer/gl/apple/DisplayApple_api.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        include "libANGLE/renderer/gl/egl/DisplayEGL.h"
 #        if defined(ANGLE_USE_GBM)
 #            include "libANGLE/renderer/gl/egl/gbm/DisplayGbm.h"
@@ -331,7 +331,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
             impl = rx::CreateDisplayCGLOrEAGL(state);
             break;
 
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -374,7 +374,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0 ||
                 platformType == EGL_PLATFORM_VULKAN_DISPLAY_MODE_HEADLESS_ANGLE)
@@ -425,7 +425,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
                 impl = rx::CreateVulkanWin32Display(state);
             }
             break;
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == EGL_PLATFORM_GBM_KHR && rx::IsVulkanGbmDisplayAvailable())
             {
@@ -1986,7 +1986,7 @@ static ClientExtensions GenerateClientExtensions()
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
