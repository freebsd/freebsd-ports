--- x11/xdata.cpp.orig	Wed Jan 19 12:54:14 2000
+++ x11/xdata.cpp	Sat Oct 25 21:49:26 2003
@@ -30,7 +30,8 @@
 #include "xdata.h"
 #include "area.h"
 
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 #include <X11/Xutil.h>
 #include <X11/xpm.h>
 #include <X11/Xatom.h>
