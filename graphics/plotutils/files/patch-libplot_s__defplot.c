
$FreeBSD$

--- libplot/s_defplot.c.orig	Sun Jul  2 18:20:20 2000
+++ libplot/s_defplot.c	Thu Aug  7 11:48:12 2003
@@ -196,13 +196,13 @@
   _s_initialize ();
 }
 
-SVGPlotter::SVGPlotter (istream& in, ostream& out, ostream& err)
+SVGPlotter::SVGPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _s_initialize ();
 }
 
-SVGPlotter::SVGPlotter (ostream& out)
+SVGPlotter::SVGPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _s_initialize ();
@@ -225,13 +225,13 @@
   _s_initialize ();
 }
 
-SVGPlotter::SVGPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+SVGPlotter::SVGPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _s_initialize ();
 }
 
-SVGPlotter::SVGPlotter (ostream& out, PlotterParams &parameters)
+SVGPlotter::SVGPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _s_initialize ();
