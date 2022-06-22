--- third_party/angle/src/libANGLE/Display.cpp.orig	2022-05-19 05:18:21 UTC
+++ third_party/angle/src/libANGLE/Display.cpp
@@ -55,7 +55,7 @@
 #        include "libANGLE/renderer/gl/wgl/DisplayWGL.h"
 #    elif defined(ANGLE_PLATFORM_MACOS) || defined(ANGLE_PLATFORM_IOS)
 #        include "libANGLE/renderer/gl/apple/DisplayApple_api.h"
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        include "libANGLE/renderer/gl/egl/DisplayEGL.h"
 #        if defined(ANGLE_USE_GBM)
 #            include "libANGLE/renderer/gl/egl/gbm/DisplayGbm.h"
@@ -320,7 +320,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
             impl = rx::CreateDisplayCGLOrEAGL(state);
             break;
 
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0)
             {
@@ -365,7 +365,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
 #if defined(ANGLE_ENABLE_OPENGL)
 #    if defined(ANGLE_PLATFORM_WINDOWS)
             impl = new rx::DisplayWGL(state);
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_GBM)
             if (platformType == 0 ||
                 platformType == EGL_PLATFORM_VULKAN_DISPLAY_MODE_HEADLESS_ANGLE)
@@ -416,7 +416,7 @@ rx::DisplayImpl *CreateDisplayFromAttribs(EGLAttrib di
                 impl = rx::CreateVulkanWin32Display(state);
             }
             break;
-#    elif defined(ANGLE_PLATFORM_LINUX)
+#    elif defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
 #        if defined(ANGLE_USE_X11)
             if (platformType == EGL_PLATFORM_X11_EXT && rx::IsVulkanXcbDisplayAvailable())
             {
@@ -1915,7 +1915,7 @@ static ClientExtensions GenerateClientExtensions()
     extensions.x11Visual = true;
 #endif
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     extensions.platformANGLEDeviceTypeEGLANGLE = true;
 #endif
 
