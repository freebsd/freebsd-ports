--- src/GridWidget.cpp.orig	Sat Nov  2 02:51:23 2002
+++ src/GridWidget.cpp	Sat Nov  2 02:53:22 2002
@@ -24,6 +24,7 @@
 
 #include "GridWidget.h"
 
+#include <iostream>
 #include <gdk/gdkkeysyms.h>
 #include <gtk--/style.h>
 
@@ -32,6 +33,8 @@
 //------------------------------------------------------------------------------
 
 #include "Namespace.h"
+
+using namespace std;
 
 NAMESPACE_OPEN
 
