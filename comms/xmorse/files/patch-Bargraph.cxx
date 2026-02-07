--- Bargraph.cxx.orig	2004-08-25 17:18:01.000000000 -0700
+++ Bargraph.cxx	2014-01-01 10:26:23.000000000 -0800
@@ -82,7 +82,7 @@
     if (child(i)->visible()) nd++;
   int dx = w()/nd;				// Slider horizontal "period"
   int width = dx*nd - gap;			// Width of slider array
-  int x0 = w()-width >> 1;			// Inset to 1st slider
+  int x0 = (w()-width) >> 1;			// Inset to 1st slider
   width = dx-gap;				// Width of individual Slider
   for (int i = 0; i < children(); i++) {	// Loop to reposition sliders
     Fl_Slider* s = (Fl_Slider*) child(i);	//   Pointer to this Slider
