--- plugins/plot_radar/gog-radar.c.orig	Sat Dec 16 23:54:55 2006
+++ plugins/plot_radar/gog-radar.c	Sun Dec 17 00:05:35 2006
@@ -386,12 +386,6 @@ GSF_DYNAMIC_CLASS (GogPolarPlot, gog_pol
 typedef GogPlotView		GogRTView;
 typedef GogPlotViewClass	GogRTViewClass;
 
-static double
-fmin (double a, double b)
-{
-	return (a < b) ? a : b;
-}
-
 static void
 gog_rt_view_render (GogView *view, GogViewAllocation const *bbox)
 {
