--- cmn/game_style.h.dist	Sat Mar 22 20:22:30 2003
+++ cmn/game_style.h	Sat Oct 25 21:41:50 2003
@@ -31,7 +31,8 @@
 #endif 
 
 #if X11
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 #endif
 #if WIN32
 #include <strstrea.h>
