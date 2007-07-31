--- x11/viewport.cpp.orig	2000-01-19 12:54:14.000000000 +0100
+++ x11/viewport.cpp	2007-07-31 15:59:37.000000000 +0200
@@ -44,7 +44,8 @@
 #include <X11/Xos.h>
 #include <X11/keysym.h>
 }
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 
 
 #define TICK_BORDER_WIDTH 5 // border width big enough for a tick mark.
@@ -1632,7 +1633,7 @@
   // Would be much better to put the radio-button logic in the Panel classes.
   if (pClosure->radio) {
     // SGI compiler says you can't cast void* to Boolean.
-    Boolean bValue = (Boolean)(int)value;
+    Boolean bValue = (Boolean)(intptr_t)value;
     if (!bValue) {
       ((TogglePanel*)panel)->set_value(True);
     }
