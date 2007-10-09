--- noegnud/noegnud_gui.c.orig	2007-10-02 14:32:19.000000000 +0200
+++ noegnud/noegnud_gui.c	2007-10-02 14:32:30.000000000 +0200
@@ -627,7 +627,7 @@
     //button=(noegnud_gui_tbutton *)noegnud_gui_create_window(parent,x,y,width,height,(sizeof(noegnud_gui_twindow)-sizeof(noegnud_gui_twidget))+datasize);
 
     text=noegnud_gui_create_text(
-				 (noegnud_gui_twidget *)button=(noegnud_gui_tbutton *)noegnud_gui_create_window(
+				 button=(noegnud_gui_tbutton *)noegnud_gui_create_window(
 														parent,
 														x,y,
 														width,height,
