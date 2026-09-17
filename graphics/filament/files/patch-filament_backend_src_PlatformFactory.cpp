-- Add FreeBSD support for Vulkan, WebGPU, and OpenGL platform creation in PlatformFactory
-- Without this, PlatformFactory::create fails to instantiate the backend on FreeBSD

--- filament/backend/src/PlatformFactory.cpp.orig	2026-09-15 21:05:50 UTC
+++ filament/backend/src/PlatformFactory.cpp
@@ -26,7 +26,7 @@
         #include "backend/platforms/WebGPUPlatformAndroid.h"
     #elif defined(__APPLE__)
         #include "backend/platforms/WebGPUPlatformApple.h"
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__FreeBSD__)
         #include "backend/platforms/WebGPUPlatformLinux.h"
     #elif defined(WIN32)
         #include "backend/platforms/WebGPUPlatformWindows.h"
@@ -50,7 +50,7 @@
         #else
             #include <backend/platforms/PlatformCocoaGL.h>
         #endif
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__FreeBSD__)
         #if defined(FILAMENT_SUPPORTS_X11)
             #include "backend/platforms/PlatformGLX.h"
         #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
@@ -70,7 +70,7 @@
         #include "backend/platforms/VulkanPlatformAndroid.h"
     #elif defined(__APPLE__)
         #include "backend/platforms/VulkanPlatformApple.h"
-    #elif defined(__linux__)
+    #elif defined(__linux__) || defined(__FreeBSD__)
         #include "backend/platforms/VulkanPlatformLinux.h"
     #elif defined(WIN32)
         #include "backend/platforms/VulkanPlatformWindows.h"
@@ -124,7 +124,7 @@ Platform* PlatformFactory::create(Backend* backend) no
                 return new VulkanPlatformAndroid();
             #elif defined(__APPLE__)
                 return new VulkanPlatformApple();
-            #elif defined(__linux__)
+            #elif defined(__linux__) || defined(__FreeBSD__)
                 return new VulkanPlatformLinux();
             #elif defined(WIN32)
                 return new VulkanPlatformWindows();
@@ -141,7 +141,7 @@ Platform* PlatformFactory::create(Backend* backend) no
                 return new WebGPUPlatformAndroid();
             #elif defined(__APPLE__)
                 return new WebGPUPlatformApple();
-            #elif defined(__linux__)
+            #elif defined(__linux__) || defined(__FreeBSD__)
                 return new WebGPUPlatformLinux();
             #elif defined(WIN32)
                 return new WebGPUPlatformWindows();
@@ -175,7 +175,7 @@ Platform* PlatformFactory::create(Backend* backend) no
             #else
                 return new PlatformCocoaGL();
             #endif
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
