
$FreeBSD$

--- libplot/i_defplot.c.orig	Thu Jun  8 23:11:11 2000
+++ libplot/i_defplot.c	Thu Aug  7 11:48:12 2003
@@ -292,13 +292,13 @@
   _i_initialize ();
 }
 
-GIFPlotter::GIFPlotter (istream& in, ostream& out, ostream& err)
+GIFPlotter::GIFPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _i_initialize ();
 }
 
-GIFPlotter::GIFPlotter (ostream& out)
+GIFPlotter::GIFPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _i_initialize ();
@@ -321,13 +321,13 @@
   _i_initialize ();
 }
 
-GIFPlotter::GIFPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+GIFPlotter::GIFPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _i_initialize ();
 }
 
-GIFPlotter::GIFPlotter (ostream& out, PlotterParams &parameters)
+GIFPlotter::GIFPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _i_initialize ();
