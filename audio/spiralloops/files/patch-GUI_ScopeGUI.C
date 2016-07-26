--- GUI/ScopeGUI.C.orig	Wed Nov 22 13:08:41 2006
+++ GUI/ScopeGUI.C	Wed Nov 22 13:10:26 2006
@@ -23,7 +23,7 @@
 
 #include <FL/fl_draw.H>
 
-ScopeWidget::ScopeWidget(int x,int y,int w,int h,const char *l=0) :
+ScopeWidget::ScopeWidget(int x,int y,int w,int h,const char *l) :
 Fl_Widget(x,y,w,h,l),
 m_Channels(1)
 {
@@ -69,7 +69,7 @@
 	if (!m_Bypass) m_Scope->redraw();
 }
 		
-void ScopeGUI::CreateGUI(int xoff=0, int yoff=0, char *name)
+void ScopeGUI::CreateGUI(int xoff, int yoff, char *name)
 {
 	 Fl_Group* o = GUIScopeGroup = new Fl_Group(xoff, yoff, 225, 110, name);
       o->type(1);
