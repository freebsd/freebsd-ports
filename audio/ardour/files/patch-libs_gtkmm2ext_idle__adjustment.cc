--- libs/gtkmm2ext/idle_adjustment.cc.orig	2018-09-03 19:39:58 UTC
+++ libs/gtkmm2ext/idle_adjustment.cc
@@ -21,6 +21,7 @@
 #include <gtkmm2ext/idle_adjustment.h>
 #include <gtkmm/main.h>
 #include <iostream>
+#include <gtkmm.h>
 
 using namespace Gtk;
 using namespace sigc;
