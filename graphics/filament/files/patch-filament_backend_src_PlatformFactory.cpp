--- filament/backend/src/PlatformFactory.cpp.orig	2023-01-26 04:37:03 UTC
+++ filament/backend/src/PlatformFactory.cpp
@@ -41,7 +41,7 @@
     #if defined(FILAMENT_DRIVER_SUPPORTS_VULKAN)
         #include "vulkan/PlatformVkCocoa.h"
     #endif
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
     #if defined(FILAMENT_SUPPORTS_GGP)
         #include "vulkan/PlatformVkLinuxGGP.h"
     #elif defined(FILAMENT_SUPPORTS_WAYLAND)
@@ -118,7 +118,7 @@ Platform* PlatformFactory::create(Backend* backend) no
                 return new PlatformVkAndroid();
             #elif defined(IOS)
                 return new PlatformVkCocoaTouch();
-            #elif defined(__linux__)
+            #elif defined(__linux__) || defined(__FreeBSD__)
                 #if defined(FILAMENT_SUPPORTS_GGP)
                     return new PlatformVkLinuxGGP();
                 #elif defined(FILAMENT_SUPPORTS_WAYLAND)
@@ -155,7 +155,7 @@ Platform* PlatformFactory::create(Backend* backend) no
             return new PlatformCocoaTouchGL();
         #elif defined(__APPLE__)
             return new PlatformCocoaGL();
-        #elif defined(__linux__)
+        #elif defined(__linux__) || defined(__FreeBSD__)
             #if defined(FILAMENT_SUPPORTS_X11)
                 return new PlatformGLX();
             #elif defined(FILAMENT_SUPPORTS_EGL_ON_LINUX)
