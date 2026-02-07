--- GUI/Widgets/Fl_Loop.C.orig	Wed Nov 22 13:15:09 2006
+++ GUI/Widgets/Fl_Loop.C	Wed Nov 22 13:15:18 2006
@@ -30,7 +30,7 @@
 static const int   INDW = 3; // indicator width
 static const int   UPDATECYCLES = 4;
 
-Fl_Loop::Fl_Loop(int x, int y, int w, int h, const char* label=0) : 
+Fl_Loop::Fl_Loop(int x, int y, int w, int h, const char* label) : 
 Fl_Double_Window(x,y,w,h,label), 
 m_data(NULL),
 m_MainWin(NULL),
