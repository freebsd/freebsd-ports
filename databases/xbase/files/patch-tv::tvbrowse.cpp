--- tv/tvbrowse.cpp.orig	Wed Sep 20 22:34:02 2000
+++ tv/tvbrowse.cpp	Sat Nov 22 22:06:16 2003
@@ -28,8 +28,8 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
-#include <iomanip.h>
-#include <strstream.h>
+#include <sstream>
+#include <iomanip>
 
 #define Uses_TEvent
 #include <tvision/tv.h>
