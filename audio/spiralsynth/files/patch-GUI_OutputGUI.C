$FreeBSD$

--- GUI/OutputGUI.C.orig	Sun Nov 26 15:52:39 2000
+++ GUI/OutputGUI.C	Mon Feb  9 12:10:10 2004
@@ -26,8 +26,10 @@ OutputGUI::OutputGUI(Output *o)
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
