--- x11/panel.cpp.orig	Sat Mar 22 20:50:44 2003
+++ x11/panel.cpp	Sat Oct 25 21:47:34 2003
@@ -31,8 +31,9 @@
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
 }
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <strstream>
+using namespace std;
 
 #include "utils.h"
 #include "xdata.h"
