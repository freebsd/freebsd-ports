
$FreeBSD$

--- libplot/c_defplot.c.orig	Thu Jun 29 10:37:52 2000
+++ libplot/c_defplot.c	Thu Aug  7 11:48:12 2003
@@ -1767,13 +1767,13 @@
   _c_initialize ();
 }
 
-CGMPlotter::CGMPlotter (istream& in, ostream& out, ostream& err)
+CGMPlotter::CGMPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _c_initialize ();
 }
 
-CGMPlotter::CGMPlotter (ostream& out)
+CGMPlotter::CGMPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _c_initialize ();
@@ -1796,13 +1796,13 @@
   _c_initialize ();
 }
 
-CGMPlotter::CGMPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+CGMPlotter::CGMPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _c_initialize ();
 }
 
-CGMPlotter::CGMPlotter (ostream& out, PlotterParams &parameters)
+CGMPlotter::CGMPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _c_initialize ();
