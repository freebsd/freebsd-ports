
$FreeBSD$

--- libplot/z_defplot.c.orig	Thu Jun  8 23:12:29 2000
+++ libplot/z_defplot.c	Thu Aug  7 11:48:12 2003
@@ -132,13 +132,13 @@
   _z_initialize ();
 }
 
-PNGPlotter::PNGPlotter (istream& in, ostream& out, ostream& err)
+PNGPlotter::PNGPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: BitmapPlotter (in, out, err)
 {
   _z_initialize ();
 }
 
-PNGPlotter::PNGPlotter (ostream& out)
+PNGPlotter::PNGPlotter (std::ostream& out)
 	: BitmapPlotter (out)
 {
   _z_initialize ();
@@ -161,13 +161,13 @@
   _z_initialize ();
 }
 
-PNGPlotter::PNGPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+PNGPlotter::PNGPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: BitmapPlotter (in, out, err, parameters)
 {
   _z_initialize ();
 }
 
-PNGPlotter::PNGPlotter (ostream& out, PlotterParams &parameters)
+PNGPlotter::PNGPlotter (std::ostream& out, PlotterParams &parameters)
 	: BitmapPlotter (out, parameters)
 {
   _z_initialize ();
