--- Fl_NSlider.cc.orig	Mon Feb  3 02:17:30 2003
+++ Fl_NSlider.cc	Mon Feb  3 02:16:37 2003
@@ -9,6 +9,7 @@
  * provided "as is" without express or implied warranty.
  */
 #include <FL/Fl_NSlider.H>
+#include <FL/Fl_Group.H>
 
 static uchar isHoz = 0;	        //for image draw setup
 static uchar r1, g1, b1;        //for color ramp
