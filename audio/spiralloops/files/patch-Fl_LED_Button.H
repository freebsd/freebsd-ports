patch by Stephen Paskaluk to enable compilation with fltk 1.1.2

--- GUI/Widgets/Fl_LED_Button.H.orig	Thu Apr 19 16:48:11 2001
+++ GUI/Widgets/Fl_LED_Button.H	Sat Mar  1 12:39:19 2003
@@ -4,6 +4,7 @@
 #define Fl_LED_Button_H
 #include <FL/Fl.H>
 #include <FL/Fl_Light_Button.H>
+#include <FL/Fl_Group.H>
 
 class Fl_LED_Button : public Fl_Light_Button {
 public:
