$FreeBSD$

--- GUI/MixerGUI.C.orig	Sun Nov 26 15:52:40 2000
+++ GUI/MixerGUI.C	Mon Feb  9 12:08:25 2004
@@ -24,8 +24,10 @@ MixerGUI::MixerGUI(Mixer *o)
 	if (!m_mix) cerr<<"WARNING: Mixer not correctly set up"<<endl;
 }
 		
-void MixerGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void MixerGUI::CreateGUI(int xoff, int yoff, char *name)
 {
+	 xoff=0;
+	 yoff=0;
 	 Fl_Group* o = GUIMixGroup = new Fl_Group(xoff, yoff, 100, 110, name);
       o->type(1);
 	  o->box(FL_UP_BOX);
