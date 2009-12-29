--- wxOil/ftfonts.cpp.orig	2009-12-12 23:53:05.000000000 +0100
+++ wxOil/ftfonts.cpp	2009-12-12 23:54:08.000000000 +0100
@@ -122,7 +122,9 @@ DECLARE_SOURCE( "$Revision: 1535 $" );
 #include FT_TYPE1_TABLES_H
 
 #ifdef __WXGTK20__
+#define GSocket GlibSocket
 #include <gtk/gtk.h>
+#undef GSocket
 extern GtkWidget *wxGetRootWindow();
 #endif
 
