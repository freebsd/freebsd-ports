
$FreeBSD$

--- libplot/a_defplot.c.orig	Wed Jun 28 11:53:44 2000
+++ libplot/a_defplot.c	Thu Aug  7 11:48:12 2003
@@ -224,13 +224,13 @@
   _a_initialize ();
 }
 
-AIPlotter::AIPlotter (istream& in, ostream& out, ostream& err)
+AIPlotter::AIPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _a_initialize ();
 }
 
-AIPlotter::AIPlotter (ostream& out)
+AIPlotter::AIPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _a_initialize ();
@@ -253,13 +253,13 @@
   _a_initialize ();
 }
 
-AIPlotter::AIPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+AIPlotter::AIPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _a_initialize ();
 }
 
-AIPlotter::AIPlotter (ostream& out, PlotterParams &parameters)
+AIPlotter::AIPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _a_initialize ();
