
$FreeBSD$

--- libplot/g_defplot.c.orig	Sun Jun 18 17:24:16 2000
+++ libplot/g_defplot.c	Thu Aug  7 11:48:12 2003
@@ -392,7 +392,7 @@
   _g_initialize ();
 }
 
-Plotter::Plotter (istream& in, ostream& out, ostream& err)
+Plotter::Plotter (std::istream& in, std::ostream& out, std::ostream& err)
 {
   /* create PlotterData structure, install it in Plotter */
   _plotter->data = (plPlotterData *)_plot_xmalloc (sizeof(plPlotterData));
@@ -420,7 +420,7 @@
   _g_initialize ();
 }
 
-Plotter::Plotter (ostream& out)
+Plotter::Plotter (std::ostream& out)
 {
   /* create PlotterData structure, install it in Plotter */
   _plotter->data = (plPlotterData *)_plot_xmalloc (sizeof(plPlotterData));
@@ -498,7 +498,7 @@
   _g_initialize ();
 }
 
-Plotter::Plotter (istream& in, ostream& out, ostream& err, PlotterParams &plotter_params)
+Plotter::Plotter (std::istream& in, std::ostream& out, std::ostream& err, PlotterParams &plotter_params)
 {
   /* create PlotterData structure, install it in Plotter */
   _plotter->data = (plPlotterData *)_plot_xmalloc (sizeof(plPlotterData));
@@ -524,7 +524,7 @@
   _g_initialize ();
 }
 
-Plotter::Plotter (ostream& out, PlotterParams &plotter_params)
+Plotter::Plotter (std::ostream& out, PlotterParams &plotter_params)
 {
   /* create PlotterData structure, install it in Plotter */
   _plotter->data = (plPlotterData *)_plot_xmalloc (sizeof(plPlotterData));
