$FreeBSD$

--- GUI/Widgets/Fl_Knob.cxx.orig	Mon Sep 11 19:52:03 2000
+++ GUI/Widgets/Fl_Knob.cxx	Mon Feb  9 13:22:13 2004
@@ -4,7 +4,7 @@
 #include <FL/fl_draw.H>
 #include <math.h>
 
-Fl_Knob::Fl_Knob(int xx,int yy,int ww,int hh,const char *l=0): Fl_Valuator(xx,yy,ww,hh,l) {
+Fl_Knob::Fl_Knob(int xx,int yy,int ww,int hh,const char *l): Fl_Valuator(xx,yy,ww,hh,0) {
   a1 = 35;
 	a2 = 325;
 	_type = DOTLIN;
@@ -40,7 +40,8 @@ unsigned char rr,gg,bb;
 	int dam = damage();
 	if (dam & FL_DAMAGE_ALL)
 	{
-		int col = parent()->color();
+//		int col = parent()->color();
+		int col = FL_BLACK;
 		fl_color(col);
 		fl_rectf(ox,oy,side,side);
 		Fl::get_color((Fl_Color)col,rr,gg,bb);
