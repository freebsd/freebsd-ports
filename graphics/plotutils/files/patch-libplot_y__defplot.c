
$FreeBSD$

--- libplot/y_defplot.c.orig	Sun Jun 18 17:29:45 2000
+++ libplot/y_defplot.c	Thu Aug  7 11:48:12 2003
@@ -265,7 +265,7 @@
   /* add to _xplotters sparse array */
 }
 
-XPlotter::XPlotter (istream& in, ostream& out, ostream& err)
+XPlotter::XPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: XDrawablePlotter (in, out, err)
 {
   _y_initialize ();
@@ -273,7 +273,7 @@
   /* add to _xplotters sparse array */
 }
 
-XPlotter::XPlotter (ostream& out)
+XPlotter::XPlotter (std::ostream& out)
 	: XDrawablePlotter (out)
 {
   _y_initialize ();
@@ -304,7 +304,7 @@
   /* add to _xplotters sparse array */
 }
 
-XPlotter::XPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+XPlotter::XPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: XDrawablePlotter (in, out, err, parameters)
 {
   _y_initialize ();
@@ -312,7 +312,7 @@
   /* add to _xplotters sparse array */
 }
 
-XPlotter::XPlotter (ostream& out, PlotterParams &parameters)
+XPlotter::XPlotter (std::ostream& out, PlotterParams &parameters)
 	: XDrawablePlotter (out, parameters)
 {
   _y_initialize ();
