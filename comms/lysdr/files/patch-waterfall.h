--- waterfall.h.orig	2011-11-26 16:01:22.000000000 -0800
+++ waterfall.h	2014-06-02 03:08:41.000000000 -0700
@@ -74,7 +74,7 @@
     gint drag;
     gint click_pos;
     gdouble bandspread;
-    GMutex *mutex;
+    GMutex mutex;
 };
 
 #define SDR_TYPE_WATERFALL             (sdr_waterfall_get_type ())
@@ -93,7 +93,7 @@
 #define SCALE_HEIGHT 24
 #define SCALE_TICK 5000
 
-GtkWidget *sdr_waterfall_new(GtkAdjustment *tuning, GtkAdjustment *lp_tune, GtkAdjustment *hp_tune, gint sample_rate, gint fft_size);
+SDRWaterfall *sdr_waterfall_new(GtkAdjustment *tuning, GtkAdjustment *lp_tune, GtkAdjustment *hp_tune, gint sample_rate, gint fft_size);
 float sdr_waterfall_get_tuning(SDRWaterfall *wf);
 float sdr_waterfall_get_lowpass(SDRWaterfall *wf);
 float sdr_waterfall_get_highpass(SDRWaterfall *wf);
@@ -102,6 +102,9 @@
 void sdr_waterfall_update(GtkWidget *widget, guchar *row);
 void sdr_waterfall_set_scale(GtkWidget *widget, gint centre_freq);
 void sdr_waterfall_filter_cursors(SDRWaterfall *wf);
+void sdr_waterfall_set_lowpass(SDRWaterfall *wf, gdouble value);
+void sdr_waterfall_set_highpass(SDRWaterfall *wf, gdouble value);
+GType sdr_waterfall_get_type(void);
 #endif /* __WATERFALL_H */
 
 /* vim: set noexpandtab ai ts=4 sw=4 tw=4: */
