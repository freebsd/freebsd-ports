--- x11/viewport.cpp.orig	Wed Jan 19 12:54:14 2000
+++ x11/viewport.cpp	Sat Oct 25 21:49:00 2003
@@ -44,7 +44,8 @@
 #include <X11/Xos.h>
 #include <X11/keysym.h>
 }
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 
 
 #define TICK_BORDER_WIDTH 5 // border width big enough for a tick mark.
