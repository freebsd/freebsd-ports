
$FreeBSD$

--- libplot/b_defplot.c.orig	Mon Jun 19 22:14:29 2000
+++ libplot/b_defplot.c	Thu Aug  7 11:48:12 2003
@@ -215,13 +215,13 @@
   _b_initialize ();
 }
 
-BitmapPlotter::BitmapPlotter (istream& in, ostream& out, ostream& err)
+BitmapPlotter::BitmapPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _b_initialize ();
 }
 
-BitmapPlotter::BitmapPlotter (ostream& out)
+BitmapPlotter::BitmapPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _b_initialize ();
@@ -244,13 +244,13 @@
   _b_initialize ();
 }
 
-BitmapPlotter::BitmapPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+BitmapPlotter::BitmapPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _b_initialize ();
 }
 
-BitmapPlotter::BitmapPlotter (ostream& out, PlotterParams &parameters)
+BitmapPlotter::BitmapPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _b_initialize ();
