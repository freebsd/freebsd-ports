--- x11/ui.cpp.orig	Wed Mar 19 10:05:38 2003
+++ x11/ui.cpp	Sat Oct 25 21:48:32 2003
@@ -40,8 +40,9 @@
 #include <X11/Xatom.h>
 }
 
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <strstream>
+using namespace std;
 
 #include "coord.h"
 #include "area.h"
