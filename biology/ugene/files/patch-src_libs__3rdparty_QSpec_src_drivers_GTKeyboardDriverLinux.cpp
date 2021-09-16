Use the Linux driver for FreeBSD as well. Fixes crash on startup.

--- src/libs_3rdparty/QSpec/src/drivers/GTKeyboardDriverLinux.cpp.orig	2021-09-08 14:18:53 UTC
+++ src/libs_3rdparty/QSpec/src/drivers/GTKeyboardDriverLinux.cpp
@@ -21,14 +21,14 @@
 
 #include "GTKeyboardDriver.h"
 
-#if defined __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #    include <X11/extensions/XTest.h>
 #    include <X11/keysym.h>
 #endif
 
 namespace HI {
 
-#if defined __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 bool GTKeyboardDriver::keyPress(char key, Qt::KeyboardModifiers modifiers) {
     DRIVER_CHECK(key != 0, "key = 0");
