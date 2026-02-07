patch by Stephen Paskaluk to enable compilation with fltk 1.1.2

--- GUI/Widgets/Fl_Knob.H.orig	Thu Apr 19 16:48:10 2001
+++ GUI/Widgets/Fl_Knob.H	Sat Mar  1 12:36:19 2003
@@ -4,6 +4,7 @@
 #define Fl_Knob_H
 #include <FL/Fl.H>
 #include <FL/Fl_Valuator.H>
+#include <FL/Fl_Group.H>
 
 class Fl_Knob : public Fl_Valuator {
 public:
