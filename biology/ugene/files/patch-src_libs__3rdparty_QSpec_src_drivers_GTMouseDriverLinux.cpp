Use the Linux driver for FreeBSD as well. Fixes crash on startup.

--- src/libs_3rdparty/QSpec/src/drivers/GTMouseDriverLinux.cpp.orig	2018-09-02 00:23:24 UTC
+++ src/libs_3rdparty/QSpec/src/drivers/GTMouseDriverLinux.cpp
@@ -23,13 +23,13 @@
 
 #include "GTMouseDriver.h"
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #    include <X11/extensions/XTest.h>
 #endif
 
 namespace HI {
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #    define GT_CLASS_NAME "GTMouseDriver Linux"
 QPoint GTMouseDriver::mousePos = QPoint(-1, -1);
