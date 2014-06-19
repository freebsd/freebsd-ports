--- gui.c.orig	2011-11-26 16:01:22.000000000 -0800
+++ gui.c	2014-06-02 03:45:03.000000000 -0700
@@ -23,6 +23,8 @@
 #include <complex.h> 
 #include <gtk/gtk.h>
 
+double complex cexp(double complex z);
+
 #include "sdr.h"
 #include "waterfall.h"
 #include "smeter.h"
@@ -31,7 +33,7 @@
 
 // these are global so that the gui_update routine can fiddle with them
 static GtkWidget *label;
-static GtkWidget *wfdisplay;
+static SDRWaterfall *wfdisplay;
 static GtkWidget *meter;
 
 /*
@@ -215,8 +217,8 @@
 	// 20m  = 14075000
 	// 15m  = 21045000
 	SDR_WATERFALL(wfdisplay)->centre_freq = sdr->centre_freq;
-	gtk_widget_set_size_request(wfdisplay, FFT_SIZE, 250);
-	gtk_box_pack_start(GTK_BOX(vbox), wfdisplay, TRUE, TRUE, 0);
+	gtk_widget_set_size_request(GTK_WIDGET(wfdisplay), FFT_SIZE, 250);
+	gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(wfdisplay), TRUE, TRUE, 0);
 	gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
 	
 	gtk_widget_show_all(mainWindow);
