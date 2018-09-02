Use the Linux driver for FreeBSD as well. Fixes crash on startup.

--- src/libs_3rdparty/QSpec/src/drivers/GTKeyboardDriverLinux.cpp.orig	2018-09-02 00:22:54 UTC
+++ src/libs_3rdparty/QSpec/src/drivers/GTKeyboardDriverLinux.cpp
@@ -22,7 +22,7 @@
 #include <cctype>
 #include "GTKeyboardDriver.h"
 
-#if defined __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     #define XK_LATIN1      // for latin symbol
     #define XK_MISCELLANY  // for action keys
     #include <X11/keysymdef.h>
@@ -31,7 +31,7 @@
 
 namespace HI {
 
-#if defined __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 
 #define GT_CLASS_NAME "GTKeyboardDriverLinux"
 
