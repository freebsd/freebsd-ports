--- ./src/main.cpp.orig	2013-06-28 17:15:02.000000000 +0200
+++ ./src/main.cpp	2013-06-28 17:15:16.000000000 +0200
@@ -34,8 +34,10 @@
 
 #ifndef ENABLE_HEADLESS
     #include "TomahawkSettingsGui.h"
+#ifdef WITH_BREAKPAD
     #include "breakpad/BreakPad.h"
 #endif
+#endif
 
 
 #ifdef Q_OS_WIN
