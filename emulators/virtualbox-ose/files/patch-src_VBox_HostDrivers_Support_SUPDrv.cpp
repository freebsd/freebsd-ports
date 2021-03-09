--- src/VBox/HostDrivers/Support/SUPDrv.cpp.orig	2018-10-15 14:30:56 UTC
+++ src/VBox/HostDrivers/Support/SUPDrv.cpp
@@ -104,7 +104,7 @@
 /** @def SUPDRV_CHECK_SMAP_CHECK
  * Checks that the AC flag is set if SMAP is enabled.  If AC is not set, it
  * will be logged and @a a_BadExpr is executed. */
-#if (defined(RT_OS_DARWIN) || defined(RT_OS_LINUX)) && !defined(VBOX_WITHOUT_EFLAGS_AC_SET_IN_VBOXDRV)
+#if (defined(RT_OS_DARWIN) || defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX)) && !defined(VBOX_WITHOUT_EFLAGS_AC_SET_IN_VBOXDRV)
 # define SUPDRV_CHECK_SMAP_SETUP() uint32_t const fKernelFeatures = SUPR0GetKernelFeatures()
 # define SUPDRV_CHECK_SMAP_CHECK(a_pDevExt, a_BadExpr) \
     do { \
