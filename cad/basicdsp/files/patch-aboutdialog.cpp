--- aboutdialog.cpp.orig	2008-08-16 23:33:09.000000000 -0400
+++ aboutdialog.cpp	2008-08-16 23:34:13.000000000 -0400
@@ -29,7 +29,7 @@
   // to clean this up would mean patching wxWidgets :(
   splash_xpm = new wxImage(basicdsp_splash_xpm);
   if (splash_xpm != NULL) 
-    splash_bitmap = new wxBitmap(splash_xpm);
+    splash_bitmap = new wxBitmap((const wxImage&)splash_xpm);
 
   if ((splash_bitmap!=NULL) && (splash_bitmap->Ok()))
   {
