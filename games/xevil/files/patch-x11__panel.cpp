--- x11/panel.cpp.orig	2012-05-27 06:52:29.000000000 +0900
+++ x11/panel.cpp	2012-05-27 06:52:58.000000000 +0900
@@ -31,13 +31,14 @@
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
 }
-#include <iostream.h>
-#include <strstream.h>
+#include <iostream>
+#include <sstream>
 
 #include "utils.h"
 #include "xdata.h"
 #include "panel.h"
 
+using namespace std;
 
 #define PANEL_BORDER 1
 #define PANEL_MARGAIN 2
@@ -311,15 +312,14 @@
 
 
 void WritePanel::update_message() {
-  ostrstream tmp;
+  stringstream tmp;
   if (active) {
-    tmp << prompt << value << "_" << ends;
+    tmp << prompt << value << "_";
   }
   else {
-    tmp << prompt << value << ends;
+    tmp << prompt << value;
   }
-  set_message(tmp.str());
-  delete tmp.str(); 
+  set_message(tmp.str().c_str());
 }
 
 
@@ -524,9 +524,8 @@
     return;
   }
 
-  ostrstream tmp;
-  tmp << "CHAT <<" << value << "\nEnter to send, Esc to cancel." << ends;
-  TextPanel::set_message(tmp.str());
-  delete tmp.str(); 
+  stringstream tmp;
+  tmp << "CHAT <<" << value << "\nEnter to send, Esc to cancel.";
+  TextPanel::set_message(tmp.str().c_str());
 }
 
