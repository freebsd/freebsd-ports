
$FreeBSD$

--- libplot/p_defplot.c.orig	Wed Jun 28 11:53:50 2000
+++ libplot/p_defplot.c	Thu Aug  7 11:48:12 2003
@@ -782,13 +782,13 @@
   _p_initialize ();
 }
 
-PSPlotter::PSPlotter (istream& in, ostream& out, ostream& err)
+PSPlotter::PSPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _p_initialize ();
 }
 
-PSPlotter::PSPlotter (ostream& out)
+PSPlotter::PSPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _p_initialize ();
@@ -811,13 +811,13 @@
   _p_initialize ();
 }
 
-PSPlotter::PSPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+PSPlotter::PSPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _p_initialize ();
 }
 
-PSPlotter::PSPlotter (ostream& out, PlotterParams &parameters)
+PSPlotter::PSPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _p_initialize ();
