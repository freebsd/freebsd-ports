
$FreeBSD$

--- libplot/n_defplot.c.orig	Thu Jun  1 14:14:43 2000
+++ libplot/n_defplot.c	Thu Aug  7 11:48:12 2003
@@ -115,13 +115,13 @@
   _n_initialize ();
 }
 
-PNMPlotter::PNMPlotter (istream& in, ostream& out, ostream& err)
+PNMPlotter::PNMPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: BitmapPlotter (in, out, err)
 {
   _n_initialize ();
 }
 
-PNMPlotter::PNMPlotter (ostream& out)
+PNMPlotter::PNMPlotter (std::ostream& out)
 	: BitmapPlotter (out)
 {
   _n_initialize ();
@@ -144,13 +144,13 @@
   _n_initialize ();
 }
 
-PNMPlotter::PNMPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+PNMPlotter::PNMPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: BitmapPlotter (in, out, err, parameters)
 {
   _n_initialize ();
 }
 
-PNMPlotter::PNMPlotter (ostream& out, PlotterParams &parameters)
+PNMPlotter::PNMPlotter (std::ostream& out, PlotterParams &parameters)
 	: BitmapPlotter (out, parameters)
 {
   _n_initialize ();
