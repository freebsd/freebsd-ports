
$FreeBSD$

--- libplot/m_defplot.c.orig	Mon Jun 19 00:10:36 2000
+++ libplot/m_defplot.c	Thu Aug  7 11:48:12 2003
@@ -204,13 +204,13 @@
   _m_initialize ();
 }
 
-MetaPlotter::MetaPlotter (istream& in, ostream& out, ostream& err)
+MetaPlotter::MetaPlotter (std::istream& in, std::ostream& out, std::ostream& err)
 	: Plotter (in, out, err)
 {
   _m_initialize ();
 }
 
-MetaPlotter::MetaPlotter (ostream& out)
+MetaPlotter::MetaPlotter (std::ostream& out)
 	: Plotter (out)
 {
   _m_initialize ();
@@ -233,13 +233,13 @@
   _m_initialize ();
 }
 
-MetaPlotter::MetaPlotter (istream& in, ostream& out, ostream& err, PlotterParams &parameters)
+MetaPlotter::MetaPlotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &parameters)
 	: Plotter (in, out, err, parameters)
 {
   _m_initialize ();
 }
 
-MetaPlotter::MetaPlotter (ostream& out, PlotterParams &parameters)
+MetaPlotter::MetaPlotter (std::ostream& out, PlotterParams &parameters)
 	: Plotter (out, parameters)
 {
   _m_initialize ();
