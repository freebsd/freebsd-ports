--- src/VBox/Additions/x11/VBoxClient/display.cpp.orig	2016-07-18 11:50:46 UTC
+++ src/VBox/Additions/x11/VBoxClient/display.cpp
@@ -75,8 +75,8 @@ static unsigned char *getRootProperty(st
 {
     Atom actualType = None;
     int iFormat = 0;
-    ulong cReturned = 0;
-    ulong cAfter = 0;
+    unsigned long cReturned = 0;
+    unsigned long cAfter = 0;
     unsigned char *pData = 0;
     
     if (XGetWindowProperty(pState->pDisplay, DefaultRootWindow(pState->pDisplay),
