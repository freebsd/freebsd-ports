--- GUI/Widgets/Fl_Knob.cxx.orig	Wed Nov 22 13:14:11 2006
+++ GUI/Widgets/Fl_Knob.cxx	Wed Nov 22 13:14:20 2006
@@ -4,7 +4,7 @@
 #include <FL/fl_draw.H>
 #include <math.h>
 
-Fl_Knob::Fl_Knob(int xx,int yy,int ww,int hh,const char *l=0): Fl_Valuator(xx,yy,ww,hh,l) {
+Fl_Knob::Fl_Knob(int xx,int yy,int ww,int hh,const char *l): Fl_Valuator(xx,yy,ww,hh,l) {
   a1 = 35;
 	a2 = 325;
 	_type = DOTLIN;
