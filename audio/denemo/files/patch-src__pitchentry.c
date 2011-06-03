--- src/pitchentry.c.orig	2011-04-27 19:59:45.153923000 +0200
+++ src/pitchentry.c	2011-05-07 11:02:38.000000000 +0200
@@ -14,7 +14,9 @@
 #define  DEFAULT_HIGH (4500.0)
 #define  DEFAULT_LOW (60.0)
 #define DEFAULT_TIMER_RATE (50)
-
+#ifndef log2(x)
+ #define log2(x)  (log(x)/log(2))
+#endif
 
 static GtkWidget *PR_window = NULL;/* a top level window for controlling pitch-recognition entry.
 			      We do not create one of these for each view (ie each DenemoGUI object, ie each score) because there is only one audio input source being used, so we would have to cope with resource contention issues, there is just no point. */
