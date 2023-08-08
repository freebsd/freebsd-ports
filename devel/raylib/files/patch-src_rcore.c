--- src/rcore.c.orig	2022-09-30 14:25:29 UTC
+++ src/rcore.c
@@ -239,6 +239,12 @@
     #endif
 #endif
 
+// TODO: HACK: Added flag if not provided by GLFW when using external library    
+// Latest GLFW release (GLFW 3.3.8) does not implement this flag, it was added for 3.4.0-dev
+#if !defined(GLFW_MOUSE_PASSTHROUGH)
+	 #define GLFW_MOUSE_PASSTHROUGH      0x0002000D
+#endif
+
 #if defined(PLATFORM_ANDROID)
     //#include <android/sensor.h>           // Required for: Android sensors functions (accelerometer, gyroscope, light...)
     #include <android/window.h>             // Required for: AWINDOW_FLAG_FULLSCREEN definition and others
