--- src/pitchentry.c.orig	2011-09-28 05:03:47.000000000 +0200
+++ src/pitchentry.c	2011-10-01 17:18:39.976734953 +0200
@@ -15,6 +15,9 @@
 #define  DEFAULT_LOW (60.0)
 #define DEFAULT_TIMER_RATE (50)
 #define QUARTER_COMMA_MEAN_TONE "Quarter comma meantone"
+#ifndef log2(x)
+#define log2(x) (log(x)/log(2))
+#endif
 
 static GtkWidget *PR_window = NULL;/* a top level window for controlling pitch-recognition entry.
 			      We do not create one of these for each view (ie each DenemoGUI object, ie each score) because there is only one audio input source being used, so we would have to cope with resource contention issues, there is just no point. */
