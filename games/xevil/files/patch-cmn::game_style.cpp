--- cmn/game_style.cpp.orig	Sat Mar 22 20:47:42 2003
+++ cmn/game_style.cpp	Sat Oct 25 21:41:21 2003
@@ -34,7 +34,8 @@
 }
 
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 
 #if WIN32
