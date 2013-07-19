--- plugins/zynaddsubfx/fltk/FL/Fl_Widget.H    2013-06-11 22:57:16.000000000 +0200
+++ plugins/zynaddsubfx/fltk/FL/Fl_Widget.H        2013-07-19 13:58:16.000000000 +0200
@@ -108,6 +108,7 @@
  */
 class FL_EXPORT Fl_Widget {
   friend class Fl_Group;
+  friend class Fl_X;
 
   Fl_Group* parent_;
   Fl_Callback* callback_;
