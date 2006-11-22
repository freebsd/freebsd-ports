--- GUI/Widgets/Fl_LED_Button.cxx.orig	Thu Apr 19 22:48:11 2001
+++ GUI/Widgets/Fl_LED_Button.cxx	Wed Nov 22 13:16:40 2006
@@ -3,7 +3,7 @@
 #include "Fl_LED_Button.H"
 #include <FL/fl_draw.H>
 
-Fl_LED_Button::Fl_LED_Button(int x, int y, int w, int h, const char* l=0):Fl_Light_Button(x,y,w,h,l) {
+Fl_LED_Button::Fl_LED_Button(int x, int y, int w, int h, const char* l):Fl_Light_Button(x,y,w,h,l) {
   box(FL_NO_BOX);
 	down_box(FL_ROUND_DOWN_BOX);
 	selection_color(FL_RED);
@@ -15,7 +15,7 @@
 void Fl_LED_Button::draw() {
   uchar r,g,b;
 
-	if (box()) draw_box(this==Fl::pushed() ? down(box()) : box(), color());
+	if (box()) draw_box(this==Fl::pushed() ? down_box() : box(), color());
 	Fl_Color col = value() ? selection_color() : color();
 	Fl::get_color((Fl_Color)selection_color(),r,g,b);
 	int d = h()/6;
