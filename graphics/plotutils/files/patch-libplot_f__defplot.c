
$FreeBSD$

--- libplot/f_defplot.c.orig	Sun Jul  2 00:08:13 2000
+++ libplot/f_defplot.c	Thu Aug  7 11:48:12 2003
@@ -191,13 +191,13 @@
   _f_initialize ();
 }
 
-FigPlotter::FigPlotter (istream& in, ostream& out, ostream& err)
+FigPlotter::FigPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _f_initialize ();
 }
 
-FigPlotter::FigPlotter (ostream& out)
+FigPlotter::FigPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _f_initialize ();
@@ -220,13 +220,13 @@
   _f_initialize ();
 }
 
-FigPlotter::FigPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+FigPlotter::FigPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _f_initialize ();
 }
 
-FigPlotter::FigPlotter (ostream& out, PlotterParams &parameters)
+FigPlotter::FigPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _f_initialize ();
