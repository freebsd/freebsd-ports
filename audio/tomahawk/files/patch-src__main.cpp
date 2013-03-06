--- ./src/main.cpp.orig	2013-02-13 21:57:24.000000000 +0100
+++ ./src/main.cpp	2013-02-13 21:57:46.000000000 +0100
@@ -34,8 +34,10 @@
 
 #ifndef ENABLE_HEADLESS
     #include "TomahawkSettingsGui.h"
+#ifdef WITH_BREAKPAD
     #include "breakpad/BreakPad.h"
 #endif
+#endif
 
 
 #ifdef Q_OS_WIN
