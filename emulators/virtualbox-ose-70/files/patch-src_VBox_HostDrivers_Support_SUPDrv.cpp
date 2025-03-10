--- src/VBox/HostDrivers/Support/SUPDrv.cpp.orig	2024-12-27 08:34:02.157677000 +0100
+++ src/VBox/HostDrivers/Support/SUPDrv.cpp	2024-12-27 08:34:25.419134000 +0100
@@ -317,8 +317,8 @@
     SUPEXP_STK_BACK(    2,  SUPR0PageFree),
     SUPEXP_STK_BACK(    6,  SUPR0PageMapKernel),
     SUPEXP_STK_BACK(    6,  SUPR0PageProtect),
-#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS) || defined(RT_OS_FREEBSD)
-    SUPEXP_STK_OKAY(    2,  SUPR0HCPhysToVirt),         /* only-linux, only-solaris, only-freebsd */
+#if defined(RT_OS_LINUX) || defined(RT_OS_SOLARIS)
+    SUPEXP_STK_OKAY(    2,  SUPR0HCPhysToVirt),         /* only-linux, only-solaris */
 #endif
     SUPEXP_STK_BACK(    2,  SUPR0PrintfV),
     SUPEXP_STK_BACK(    1,  SUPR0GetSessionGVM),
