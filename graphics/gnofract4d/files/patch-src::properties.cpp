--- src/properties.cpp.orig	Tue Jan 21 12:59:50 2003
+++ src/properties.cpp	Fri Oct 17 22:35:26 2003
@@ -30,6 +30,7 @@
 #include <gnome.h>
 #include "gf4d_fractal.h"
 #include "iterFunc.h"
+#include <cassert>
 #include <cstdlib>
 
 GtkWidget *global_propertybox=NULL;
