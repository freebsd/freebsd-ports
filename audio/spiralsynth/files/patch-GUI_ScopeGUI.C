$FreeBSD$

--- GUI/ScopeGUI.C.orig	Sun Nov 26 15:52:39 2000
+++ GUI/ScopeGUI.C	Mon Feb  9 12:14:00 2004
@@ -22,8 +22,8 @@
 
 #include <FL/fl_draw.H>
 
-ScopeWidget::ScopeWidget(int x,int y,int w,int h,const char *l=0) :
-Fl_Widget(x,y,w,h,l)
+ScopeWidget::ScopeWidget(int x,int y,int w,int h,const char *l) :
+Fl_Widget(x,y,w,h,0)
 {
 }
 
@@ -53,8 +53,10 @@ void ScopeGUI::Display(short *data)
 	if (!m_Bypass) m_Scope->redraw();
 }
 		
-void ScopeGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void ScopeGUI::CreateGUI(int xoff, int yoff, char *name)
 {
+	 xoff=0;
+	 yoff=0;
 	 Fl_Group* o = GUIScopeGroup = new Fl_Group(xoff, yoff, 225, 110, name);
       o->type(1);
 	  o->box(FL_UP_BOX);
