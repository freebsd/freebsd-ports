patch by Stephen Paskaluk to enable compilation with fltk 1.1.2

--- GUI/Widgets/Fl_LED_Button.cxx.orig	Thu Apr 19 16:48:11 2001
+++ GUI/Widgets/Fl_LED_Button.cxx	Sat Mar  1 12:38:27 2003
@@ -15,7 +15,7 @@ Fl_LED_Button::~Fl_LED_Button() {
 void Fl_LED_Button::draw() {
   uchar r,g,b;
 
-	if (box()) draw_box(this==Fl::pushed() ? down(box()) : box(), color());
+	if (box()) draw_box(this==Fl::pushed() ? down_box() : box(), color());
 	Fl_Color col = value() ? selection_color() : color();
 	Fl::get_color((Fl_Color)selection_color(),r,g,b);
 	int d = h()/6;
