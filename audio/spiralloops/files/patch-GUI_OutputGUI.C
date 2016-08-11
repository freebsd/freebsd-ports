--- GUI/OutputGUI.C.orig	Wed Nov 22 13:13:17 2006
+++ GUI/OutputGUI.C	Wed Nov 22 13:13:32 2006
@@ -26,7 +26,7 @@
 	if (!m_out) cerr<<"WARNING: Output not correctly set up"<<endl;
 }
 		
-void OutputGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void OutputGUI::CreateGUI(int xoff, int yoff, char *name)
 {
 	 Fl_Group* o = GUIMixGroup = new Fl_Group(xoff, yoff, 85, 110, name);
       o->type(1);
