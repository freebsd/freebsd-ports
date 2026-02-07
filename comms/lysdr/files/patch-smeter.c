--- smeter.c.orig	2014-06-02 02:39:40.000000000 -0700
+++ smeter.c	2014-06-02 02:40:19.000000000 -0700
@@ -85,6 +85,7 @@
 	cairo_fill(cr);
 
 	cairo_destroy(cr);
+	return TRUE;
 }
 
 void sdr_smeter_set_level(SDRSMeter *sm, gdouble level) {
