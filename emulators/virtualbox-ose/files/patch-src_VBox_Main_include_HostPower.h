--- src/VBox/Main/include/HostPower.h.orig	2017-10-18 07:12:54 UTC
+++ src/VBox/Main/include/HostPower.h
@@ -28,7 +28,7 @@
 
 #include <vector>
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 # include <VBox/dbus.h>
 #endif
 
@@ -64,7 +64,7 @@ class HostPowerServiceWin : public HostPowerService (p
     RTTHREAD    mThread;
 };
 # endif
-# if defined(RT_OS_LINUX) || defined(DOXYGEN_RUNNING)
+# if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(DOXYGEN_RUNNING)
 /**
  * The Linux hosted Power Service.
  */
