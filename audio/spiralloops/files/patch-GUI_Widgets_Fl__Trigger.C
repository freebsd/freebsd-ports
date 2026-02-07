--- GUI/Widgets/Fl_Trigger.C.orig	Wed Nov 22 13:17:29 2006
+++ GUI/Widgets/Fl_Trigger.C	Wed Nov 22 13:17:36 2006
@@ -27,7 +27,7 @@
 
 static const float RADCONV = 0.017453292;
 
-Fl_Trigger::Fl_Trigger(int x, int y, int w, int h, const char* label=0) : 
+Fl_Trigger::Fl_Trigger(int x, int y, int w, int h, const char* label) : 
 Fl_Widget(x,y,w,h,label),
 m_CentreX(0),
 m_CentreY(0),
