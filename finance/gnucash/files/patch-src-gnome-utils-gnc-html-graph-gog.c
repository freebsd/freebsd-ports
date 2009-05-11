--- src/gnome-utils/gnc-html-graph-gog.c.orig	2008-01-08 02:06:26.000000000 +0100
+++ src/gnome-utils/gnc-html-graph-gog.c	2009-05-04 23:45:42.167617782 +0200
@@ -46,7 +46,22 @@
 #ifndef GTKHTML_USES_GTKPRINT
 #    include <goffice/graph/gog-renderer-gnome-print.h>
 #endif
-#include <goffice/graph/gog-style.h>
+/* everything inside the following #ifndef can be safely removed when gnucash 
+requires libgoffice >= 0.7.5. */ 
+#ifndef GOG_TYPE_GRAPH 
+#       define GOG_TYPE_GRAPH GOG_GRAPH_TYPE 
+#       define GOG_TYPE_RENDERER GOG_RENDERER_TYPE 
+#       define GO_TYPE_PLUGIN_LOADER_MODULE GO_PLUGIN_LOADER_MODULE_TYPE 
+#       include <goffice/graph/gog-style.h> 
+#       define GOStyle GogStyle 
+#       define go_styled_object_get_style gog_styled_object_get_style 
+#       define GO_STYLED_OBJECT GOG_STYLED_OBJECT 
+#       define GO_STYLE_FILL_PATTERN GOG_FILL_STYLE_PATTERN 
+#       define go_style_set_text_angle gog_style_set_text_angle 
+#else 
+#       include <goffice/utils/go-style.h> 
+#       include <goffice/utils/go-styled-object.h> 
+#endif 
 #include <goffice/graph/gog-styled-object.h>
 #include <goffice/graph/gog-plot.h>
 #include <goffice/graph/gog-series.h>
@@ -98,7 +113,7 @@
   libgoffice_init();
   
   /* Initialize plugins manager */
-  go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+  go_plugins_init( NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE );
 
   gnc_html_register_object_handler( "gnc-guppi-pie", handle_piechart );
   gnc_html_register_object_handler( "gnc-guppi-bar", handle_barchart );
@@ -189,7 +204,7 @@
   gog_object_update (GOG_OBJECT (graph));
 
 #if defined(HAVE_GOFFICE_0_5)
-  renderer = GOG_RENDERER (g_object_new (GOG_RENDERER_TYPE,
+  renderer = GOG_RENDERER (g_object_new (GOG_TYPE_RENDERER,
 					 "model", graph,
 					 NULL));
   update_status = gog_renderer_update (renderer, eb->width, eb->height);
@@ -229,7 +244,7 @@
                            GogObject **out_chart,
                            GogPlot **out_plot)
 {
-  *out_graph = g_object_new(GOG_GRAPH_TYPE, NULL);
+  *out_graph = g_object_new(GOG_TYPE_GRAPH, NULL);
   *out_chart = gog_object_add_by_name(*out_graph, "Chart", NULL);
   *out_plot = gog_plot_new_by_name(plot_type_name);
   if (!*out_plot)
@@ -401,7 +416,7 @@
   GogObject *graph, *chart;
   GogPlot *plot;
   GogSeries *series;
-  GogStyle *style;
+  GOStyle *style;
   GOData *label_data, *slice_data;
   int data_rows, data_cols;
   double *data = NULL;
@@ -489,8 +504,8 @@
       gog_series_set_dim (series, 1, slice_data, NULL);
       go_data_emit_changed (GO_DATA (slice_data));
 
-      style = gog_styled_object_get_style (GOG_STYLED_OBJECT (series));
-      style->fill.type = GOG_FILL_STYLE_PATTERN;
+      style = go_styled_object_get_style( GO_STYLED_OBJECT(series) ); 
+      style->fill.type = GO_STYLE_FILL_PATTERN; 
       if (gdk_color_parse (col_colors[i], &color)) {
            style->fill.auto_back = FALSE;
            go_pattern_set_solid (&style->fill.pattern, GDK_TO_UINT (color));
@@ -503,8 +518,8 @@
   if (rotate_row_labels) {
     GogObject *object = gog_object_get_child_by_role (
       chart, gog_object_find_role_by_name (chart, "X-Axis"));
-    style = gog_styled_object_get_style (GOG_STYLED_OBJECT (object));
-    gog_style_set_text_angle (style, 90.0);
+      style = go_styled_object_get_style( GO_STYLED_OBJECT(object) ); 
+      go_style_set_text_angle( style, 90.0 ); 
   }
 
   set_chart_titles_from_hash (chart, eb);
@@ -526,7 +541,7 @@
   GogPlot *plot;
   GogSeries *series;
   GOData *sliceData;
-  GogStyle *style;
+  GOStyle *style;
   int datasize;
   double *xData, *yData;
   gchar *marker_str, *color_str;
@@ -556,7 +571,7 @@
   }
 
   series = gog_plot_new_series( plot );
-  style = gog_styled_object_get_style(GOG_STYLED_OBJECT(series));
+  style = go_styled_object_get_style(GO_STYLED_OBJECT(series));
 
   sliceData = go_data_vector_val_new( xData, datasize, NULL );
   gog_series_set_dim( series, 0, sliceData, NULL );
@@ -602,15 +617,15 @@
     go_marker_set_fill_color(style->marker.mark,
                              go_marker_get_outline_color(style->marker.mark));
   } else {
-    GogStyle *chart_style =
-      gog_styled_object_get_style(GOG_STYLED_OBJECT(chart));
+    GOStyle *chart_style =
+      go_styled_object_get_style(GO_STYLED_OBJECT(chart));
 
-    if (chart_style->fill.type == GOG_FILL_STYLE_PATTERN
+    if (chart_style->fill.type == GO_STYLE_FILL_PATTERN
         && chart_style->fill.pattern.pattern == GO_PATTERN_SOLID) {
       style->marker.auto_fill_color = FALSE;
       go_marker_set_fill_color(style->marker.mark,
                                chart_style->fill.pattern.back);
-    } else if (chart_style->fill.type == GOG_FILL_STYLE_PATTERN
+    } else if (chart_style->fill.type == GO_STYLE_FILL_PATTERN
                && chart_style->fill.pattern.pattern
                == GO_PATTERN_FOREGROUND_SOLID) {
       style->marker.auto_fill_color = FALSE;
@@ -639,7 +654,7 @@
 {
   GogGraph *graph = GOG_GRAPH(g_object_get_data(G_OBJECT(eb), "graph"));
 #    ifdef HAVE_GOFFICE_0_5
-  GogRenderer *rend = g_object_new(GOG_RENDERER_TYPE, "model", graph, NULL);
+  GogRenderer *rend = g_object_new(GOG_TYPE_RENDERER, "model", graph, NULL);
 #    else
   GogRendererCairo *rend = g_object_new(GOG_RENDERER_CAIRO_TYPE, "model", graph,
                                         "cairo", cr, "is-vector", TRUE, NULL);
