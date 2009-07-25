--- Fltk/aboutWindow.cpp-xxx	2009-07-20 16:56:09.000000000 -0500
+++ Fltk/aboutWindow.cpp	2009-07-20 16:56:21.000000000 -0500
@@ -13,6 +13,7 @@
 #include "StringUtils.h"
 #include "OS.h"
 #include "Context.h"
+#include <cstdio>
 
 static void help_license_cb(Fl_Widget *w, void *data)
 {
