--- cmn/game.cpp.orig	Sat Mar 22 22:20:00 2003
+++ cmn/game.cpp	Sat Oct 25 21:40:23 2003
@@ -34,7 +34,8 @@
 }
 
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 #if WIN32
 #include <strstrea.h>
