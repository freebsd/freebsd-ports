--- src/gnome-utils/gnc-html-graph-gog.c.orig	2008-01-08 02:06:26.000000000 +0100
+++ src/gnome-utils/gnc-html-graph-gog.c	2009-09-21 10:43:38.000000000 +0200
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
@@ -98,7 +113,7 @@ gnc_html_graph_gog_init(void)
   libgoffice_init();
   
   /* Initialize plugins manager */
-  go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
+  go_plugins_init( NULL, NULL, NULL, NULL, TRUE, GO_TYPE_PLUGIN_LOADER_MODULE );
 
   gnc_html_register_object_handler( "gnc-guppi-pie", handle_piechart );
   gnc_html_register_object_handler( "gnc-guppi-bar", handle_barchart );
@@ -189,7 +204,7 @@ add_pixbuf_graph_widget( GtkHTMLEmbedded
   gog_object_update (GOG_OBJECT (graph));
 
 #if defined(HAVE_GOFFICE_0_5)
-  renderer = GOG_RENDERER (g_object_new (GOG_RENDERER_TYPE,
+  renderer = GOG_RENDERER (g_object_new (GOG_TYPE_RENDERER,
 					 "model", graph,
 					 NULL));
   update_status = gog_renderer_update (renderer, eb->width, eb->height);
@@ -229,7 +244,7 @@ create_basic_plot_elements(const char *p
                            GogObject **out_chart,
                            GogPlot **out_plot)
 {
-  *out_graph = g_object_new(GOG_GRAPH_TYPE, NULL);
+  *out_graph = g_object_new(GOG_TYPE_GRAPH, NULL);
   *out_chart = gog_object_add_by_name(*out_graph, "Chart", NULL);
   *out_plot = gog_plot_new_by_name(plot_type_name);
   if (!*out_plot)
@@ -363,8 +378,8 @@ handle_piechart(gnc_html * html, GtkHTML
   }
   gog_object_add_by_name(chart, "Legend", NULL);
 
-  GOG_STYLED_OBJECT(graph)->style->outline.width = 5;
-  GOG_STYLED_OBJECT(graph)->style->outline.color = RGBA_BLACK;
+  GOG_STYLED_OBJECT(graph)->style->line.width = 5;
+  GOG_STYLED_OBJECT(graph)->style->line.color = GO_COLOR_BLACK;
 
   series = gog_plot_new_series(plot);
   labelData = go_data_vector_str_new((char const * const *)labels, datasize, NULL);
@@ -401,7 +416,7 @@ handle_barchart(gnc_html * html, GtkHTML
   GogObject *graph, *chart;
   GogPlot *plot;
   GogSeries *series;
-  GogStyle *style;
+  GOStyle *style;
   GOData *label_data, *slice_data;
   int data_rows, data_cols;
   double *data = NULL;
@@ -489,11 +504,11 @@ handle_barchart(gnc_html * html, GtkHTML
       gog_series_set_dim (series, 1, slice_data, NULL);
       go_data_emit_changed (GO_DATA (slice_data));
 
-      style = gog_styled_object_get_style (GOG_STYLED_OBJECT (series));
-      style->fill.type = GOG_FILL_STYLE_PATTERN;
+      style = go_styled_object_get_style( GO_STYLED_OBJECT(series) ); 
+      style->fill.type = GO_STYLE_FILL_PATTERN; 
       if (gdk_color_parse (col_colors[i], &color)) {
            style->fill.auto_back = FALSE;
-           go_pattern_set_solid (&style->fill.pattern, GDK_TO_UINT (color));
+           go_pattern_set_solid (&style->fill.pattern, GO_COLOR_FROM_GDK (color));
       } else {
            g_warning("cannot parse color [%s]", col_colors[i]);
       }
@@ -503,8 +518,8 @@ handle_barchart(gnc_html * html, GtkHTML
   if (rotate_row_labels) {
     GogObject *object = gog_object_get_child_by_role (
       chart, gog_object_find_role_by_name (chart, "X-Axis"));
-    style = gog_styled_object_get_style (GOG_STYLED_OBJECT (object));
-    gog_style_set_text_angle (style, 90.0);
+      style = go_styled_object_get_style( GO_STYLED_OBJECT(object) ); 
+      go_style_set_text_angle( style, 90.0 ); 
   }
 
   set_chart_titles_from_hash (chart, eb);
@@ -526,7 +541,7 @@ handle_scatter(gnc_html * html, GtkHTMLE
   GogPlot *plot;
   GogSeries *series;
   GOData *sliceData;
-  GogStyle *style;
+  GOStyle *style;
   int datasize;
   double *xData, *yData;
   gchar *marker_str, *color_str;
@@ -556,7 +571,7 @@ handle_scatter(gnc_html * html, GtkHTMLE
   }
 
   series = gog_plot_new_series( plot );
-  style = gog_styled_object_get_style(GOG_STYLED_OBJECT(series));
+  style = go_styled_object_get_style(GO_STYLED_OBJECT(series));
 
   sliceData = go_data_vector_val_new( xData, datasize, NULL );
   gog_series_set_dim( series, 0, sliceData, NULL );
@@ -588,9 +603,9 @@ handle_scatter(gnc_html * html, GtkHTMLE
     GdkColor color;
     if (gdk_color_parse(color_str, &color)) {
       style->marker.auto_outline_color = FALSE;
-      go_marker_set_outline_color(style->marker.mark, GDK_TO_UINT(color));
+      go_marker_set_outline_color(style->marker.mark, GO_COLOR_FROM_GDK(color));
       style->line.auto_color = FALSE;
-      style->line.color = GDK_TO_UINT(color);
+      style->line.color = GO_COLOR_FROM_GDK(color);
     } else {
       g_warning("cannot parse color [%s]", color_str);
     }
@@ -602,15 +617,15 @@ handle_scatter(gnc_html * html, GtkHTMLE
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
@@ -639,7 +654,7 @@ draw_print_cb(GtkHTMLEmbedded *eb, cairo
 {
   GogGraph *graph = GOG_GRAPH(g_object_get_data(G_OBJECT(eb), "graph"));
 #    ifdef HAVE_GOFFICE_0_5
-  GogRenderer *rend = g_object_new(GOG_RENDERER_TYPE, "model", graph, NULL);
+  GogRenderer *rend = g_object_new(GOG_TYPE_RENDERER, "model", graph, NULL);
 #    else
   GogRendererCairo *rend = g_object_new(GOG_RENDERER_CAIRO_TYPE, "model", graph,
                                         "cairo", cr, "is-vector", TRUE, NULL);
