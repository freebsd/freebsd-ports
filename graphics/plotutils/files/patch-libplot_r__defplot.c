
$FreeBSD$

--- libplot/r_defplot.c.orig	Mon Jun 19 23:39:42 2000
+++ libplot/r_defplot.c	Thu Aug  7 11:48:12 2003
@@ -170,13 +170,13 @@
   _r_initialize ();
 }
 
-ReGISPlotter::ReGISPlotter (istream& in, ostream& out, ostream& err)
+ReGISPlotter::ReGISPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _r_initialize ();
 }
 
-ReGISPlotter::ReGISPlotter (ostream& out)
+ReGISPlotter::ReGISPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _r_initialize ();
@@ -199,13 +199,13 @@
   _r_initialize ();
 }
 
-ReGISPlotter::ReGISPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+ReGISPlotter::ReGISPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _r_initialize ();
 }
 
-ReGISPlotter::ReGISPlotter (ostream& out, PlotterParams &parameters)
+ReGISPlotter::ReGISPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _r_initialize ();
