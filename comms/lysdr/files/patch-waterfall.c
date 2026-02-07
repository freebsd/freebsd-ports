--- waterfall.c.orig	2011-11-26 16:01:22.000000000 -0800
+++ waterfall.c	2014-06-02 03:12:20.000000000 -0700
@@ -21,6 +21,7 @@
 */
 
 #include <math.h>
+#include <stdlib.h>
 #include <string.h>
 
 #include <gtk/gtk.h>
@@ -38,8 +39,6 @@
 static void sdr_waterfall_realize(GtkWidget *widget);
 static void sdr_waterfall_unrealize(GtkWidget *widget);
 static void sdr_waterfall_draw_scale(GtkWidget *widget);
-void sdr_waterfall_set_lowpass(SDRWaterfall *wf, gdouble value);
-void sdr_waterfall_set_highpass(SDRWaterfall *wf, gdouble value);
 
 static void sdr_waterfall_class_init (SDRWaterfallClass *class) {
     GtkWidgetClass *widget_class = GTK_WIDGET_CLASS(class);
@@ -132,8 +131,7 @@
     
     sdr_waterfall_set_scale(widget, wf->centre_freq);
     
-    g_assert(priv->mutex == NULL);
-    priv->mutex = g_mutex_new();
+    g_mutex_init(&priv->mutex);
     gtk_adjustment_value_changed(wf->tuning);
 }
 
@@ -146,7 +144,7 @@
     if (wf->scale) // we might not have a scale
         g_object_unref(wf->scale);
 
-    g_mutex_free(priv->mutex);
+    g_mutex_clear(&priv->mutex);
     GTK_WIDGET_CLASS(parent_class)->unrealize(widget);
 }
 
@@ -184,7 +182,7 @@
     gtk_widget_queue_draw(GTK_WIDGET(wf));
 }
 
-GtkWidget *sdr_waterfall_new(GtkAdjustment *tuning, GtkAdjustment *lp_tune, GtkAdjustment *hp_tune, gint sample_rate, gint fft_size) {
+SDRWaterfall *sdr_waterfall_new(GtkAdjustment *tuning, GtkAdjustment *lp_tune, GtkAdjustment *hp_tune, gint sample_rate, gint fft_size) {
     // call this with three Adjustments, for tuning, lowpass filter and highpass filter
     // the tuning Adjustment should have its upper and lower bounds set to half the sample rate
     SDRWaterfall *wf;
@@ -209,7 +207,7 @@
         G_CALLBACK (sdr_waterfall_lowpass_changed), wf);
     g_signal_connect (hp_tune, "value-changed",
         G_CALLBACK (sdr_waterfall_highpass_changed), wf);
-    return GTK_WIDGET(wf);
+    return wf;
     
 }
 
@@ -328,6 +326,7 @@
         gtk_widget_queue_draw(widget);
         priv->prelight = prelight;
     }
+    return TRUE;
 }
 
 static gboolean sdr_waterfall_button_press(GtkWidget *widget, GdkEventButton *event) {
@@ -358,6 +357,7 @@
             gtk_widget_queue_draw(widget);
             break;
     }
+    return TRUE;
 }
 
 static gboolean sdr_waterfall_button_release(GtkWidget *widget, GdkEventButton *event) {
@@ -392,6 +392,8 @@
         case GDK_SCROLL_DOWN:
             tuning += step;
             break;
+        default:
+            break;
     }
 
     sdr_waterfall_set_tuning(wf, tuning);
@@ -418,12 +420,12 @@
     cairo_rectangle(cr, 0, 0, width, height);
     cairo_clip(cr);
 
-    g_mutex_lock(priv->mutex);
+    g_mutex_lock(&priv->mutex);
 	gdk_cairo_set_source_pixmap(cr, wf->pixmap, 0, -priv->scroll_pos);
 	cairo_paint(cr);
 	gdk_cairo_set_source_pixmap(cr, wf->pixmap, 0, height-priv->scroll_pos);
 	cairo_paint(cr);
-    g_mutex_unlock(priv->mutex);
+    g_mutex_unlock(&priv->mutex);
 
     // cursor is translucent when "off", opaque when prelit
     cursor = priv->cursor_pos;
@@ -486,10 +488,10 @@
         (4*wf->fft_size)
     );
     
-    g_mutex_lock(priv->mutex);
+    g_mutex_lock(&priv->mutex);
     cairo_set_source_surface (cr, s_row, 0, priv->scroll_pos);
     cairo_paint(cr);
-    g_mutex_unlock(priv->mutex);
+    g_mutex_unlock(&priv->mutex);
 
     priv->scroll_pos++;
     if (priv->scroll_pos >= wf->wf_height) priv->scroll_pos = 0;
