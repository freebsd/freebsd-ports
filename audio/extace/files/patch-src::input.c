--- src/input.c.orig	Mon Aug 23 23:35:00 2004
+++ src/input.c	Sun Oct 31 00:44:56 2004
@@ -52,8 +52,12 @@
 } handles[MAX_HANDLES];
 
 static GtkWidget *errbox;
+GtkWidget *label;
 static int errorbox_up =0;
 gint tag;		/* Used by gdk_input_* */
+gint timeo;
+gint res;
+gint to_get;
 
 /*--- globals to this file */
 
@@ -295,7 +299,6 @@
 	
 	/* The rest is error handling */
 
-	GtkWidget *label;
 	if (errorbox_up)
 		return(-1); /* ERROR window already onscreen */
 	errbox = gtk_window_new(GTK_WINDOW_DIALOG);
@@ -536,9 +539,9 @@
 	struct pollfd ufds;
 	ufds.fd = source;
 	ufds.events = POLLIN;
-	gint timeo = 100; /* wait 100ms max before timeout */
-	gint res = -1;
-	gint to_get = 0;
+	timeo = 100; /* wait 100ms max before timeout */
+	res = -1;
+	to_get = 0;
      
 	/* adjust position in ring buffer to be on first channel */
 	ring_pos -= ring_pos%ring_channels;
