--- GUI/OutputGUI.C.orig	2000-11-26 16:52:39.000000000 +0100
+++ GUI/OutputGUI.C	2011-11-15 14:11:31.000000000 +0100
@@ -18,7 +18,7 @@
 
 #include "OutputGUI.h"
 
-#include <FL/fl_file_chooser.h>
+#include <FL/Fl_File_Chooser.H>
 
 OutputGUI::OutputGUI(Output *o)
 {
@@ -26,8 +26,10 @@
 	if (!m_out) cerr<<"WARNING: Output not correctly set up"<<endl;
 }
 		
-void OutputGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void OutputGUI::CreateGUI(int xoff, int yoff, char *name)
 {
+	 xoff=0;
+	 yoff=0;
 	 Fl_Group* o = GUIMixGroup = new Fl_Group(xoff, yoff, 85, 110, name);
       o->type(1);
 	  o->box(FL_UP_BOX);
