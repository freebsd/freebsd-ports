
$FreeBSD$

--- libplot/h_defplot.c.orig	Sun Jul  2 15:03:52 2000
+++ libplot/h_defplot.c	Thu Aug  7 11:48:12 2003
@@ -805,13 +805,13 @@
   _h_initialize ();
 }
 
-HPGLPlotter::HPGLPlotter (istream& in, ostream& out, ostream& err)
+HPGLPlotter::HPGLPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _h_initialize ();
 }
 
-HPGLPlotter::HPGLPlotter (ostream& out)
+HPGLPlotter::HPGLPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _h_initialize ();
@@ -834,13 +834,13 @@
   _h_initialize ();
 }
 
-HPGLPlotter::HPGLPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+HPGLPlotter::HPGLPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _h_initialize ();
 }
 
-HPGLPlotter::HPGLPlotter (ostream& out, PlotterParams &parameters)
+HPGLPlotter::HPGLPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _h_initialize ();
@@ -875,13 +875,13 @@
   _q_initialize ();
 }
 
-PCLPlotter::PCLPlotter (istream& in, ostream& out, ostream& err)
+PCLPlotter::PCLPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: HPGLPlotter (in, out, err)
 {
   _q_initialize ();
 }
 
-PCLPlotter::PCLPlotter (ostream& out)
+PCLPlotter::PCLPlotter (std::ostream& out)
 	: HPGLPlotter (out)
 {
   _q_initialize ();
@@ -904,13 +904,13 @@
   _q_initialize ();
 }
 
-PCLPlotter::PCLPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+PCLPlotter::PCLPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: HPGLPlotter (in, out, err, parameters)
 {
   _q_initialize ();
 }
 
-PCLPlotter::PCLPlotter (ostream& out, PlotterParams &parameters)
+PCLPlotter::PCLPlotter (std::ostream& out, PlotterParams &parameters)
 	: HPGLPlotter (out, parameters)
 {
   _q_initialize ();
