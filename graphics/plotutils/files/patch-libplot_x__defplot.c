
$FreeBSD$

--- libplot/x_defplot.c.orig	Sun Jun 18 17:30:02 2000
+++ libplot/x_defplot.c	Thu Aug  7 11:48:12 2003
@@ -226,13 +226,13 @@
   _x_initialize ();
 }
 
-XDrawablePlotter::XDrawablePlotter (istream& in, ostream& out, ostream& err)
+XDrawablePlotter::XDrawablePlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _x_initialize ();
 }
 
-XDrawablePlotter::XDrawablePlotter (ostream& out)
+XDrawablePlotter::XDrawablePlotter (std::ostream& out)
 	: Plotter (out)
 {
   _x_initialize ();
@@ -255,13 +255,13 @@
   _x_initialize ();
 }
 
-XDrawablePlotter::XDrawablePlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+XDrawablePlotter::XDrawablePlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _x_initialize ();
 }
 
-XDrawablePlotter::XDrawablePlotter (ostream& out, PlotterParams &parameters)
+XDrawablePlotter::XDrawablePlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _x_initialize ();
