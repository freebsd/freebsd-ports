
$FreeBSD$

--- libplot/t_defplot.c.orig	Mon Jun  5 22:20:07 2000
+++ libplot/t_defplot.c	Thu Aug  7 11:48:12 2003
@@ -195,13 +195,13 @@
   _t_initialize ();
 }
 
-TekPlotter::TekPlotter (istream& in, ostream& out, ostream& err)
+TekPlotter::TekPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _t_initialize ();
 }
 
-TekPlotter::TekPlotter (ostream& out)
+TekPlotter::TekPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _t_initialize ();
@@ -224,13 +224,13 @@
   _t_initialize ();
 }
 
-TekPlotter::TekPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+TekPlotter::TekPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _t_initialize ();
 }
 
-TekPlotter::TekPlotter (ostream& out, PlotterParams &parameters)
+TekPlotter::TekPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _t_initialize ();
