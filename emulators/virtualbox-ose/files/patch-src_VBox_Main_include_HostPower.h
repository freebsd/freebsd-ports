--- src/VBox/Main/include/HostPower.h.orig	2017-03-08 17:20:12 UTC
+++ src/VBox/Main/include/HostPower.h
@@ -28,7 +28,7 @@
 
 #include <vector>
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 # include <VBox/dbus.h>
 #endif
 
@@ -63,7 +63,7 @@ private:
     HWND        mHwnd;
     RTTHREAD    mThread;
 };
-#elif defined(RT_OS_LINUX)
+#elif defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 /**
  * The Linux hosted Power Service.
  */
