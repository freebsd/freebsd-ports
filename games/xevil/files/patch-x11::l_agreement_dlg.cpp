--- x11/l_agreement_dlg.cpp.orig	Wed Jan 19 12:55:04 2000
+++ x11/l_agreement_dlg.cpp	Sat Oct 25 21:46:33 2003
@@ -31,7 +31,8 @@
 #include <X11/Xatom.h>
 }
 
-#include <strstream.h>
+#include <strstream>
+using namespace std;
 
 #include "xdata.h"
 #include "panel.h"
