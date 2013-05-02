--- ./src/main.cpp.orig	2013-03-24 10:41:13.000000000 +0100
+++ ./src/main.cpp	2013-04-29 22:46:47.000000000 +0200
@@ -34,8 +34,10 @@
 
 #ifndef ENABLE_HEADLESS
     #include "TomahawkSettingsGui.h"
+#ifdef WITH_BREAKPAD
     #include "breakpad/BreakPad.h"
 #endif
+#endif
 
 
 #ifdef Q_OS_WIN
