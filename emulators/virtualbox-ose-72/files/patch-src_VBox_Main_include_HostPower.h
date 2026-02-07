--- src/VBox/Main/include/HostPower.h.orig	2025-08-13 19:51:21 UTC
+++ src/VBox/Main/include/HostPower.h
@@ -41,7 +41,7 @@
 
 #include <vector>
 
-#ifdef RT_OS_LINUX
+#if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD)
 # include <VBox/dbus.h>
 #endif
 
@@ -77,7 +77,7 @@ class HostPowerServiceWin : public HostPowerService (p
     RTTHREAD    mThread;
 };
 # endif
-# if defined(RT_OS_LINUX) || defined(DOXYGEN_RUNNING)
+# if defined(RT_OS_LINUX) || defined(RT_OS_FREEBSD) || defined(DOXYGEN_RUNNING)
 /**
  * The Linux hosted Power Service.
  */
