--- src/input.c.orig	Sat Nov 29 14:05:28 2003
+++ src/input.c	Sun Nov 30 13:24:14 2003
@@ -15,7 +15,7 @@
  * No warranty is made or implied. You use this program at your own risk.
  */
 
-#include <asm/errno.h>
+#include <errno.h>
 #include <config.h>
 #include <enums.h>
 #include <fcntl.h>
@@ -76,8 +76,12 @@
 static gchar channel_numbers[MAX_STR][10];  /* string containing integers */
 #endif
 GtkWidget *errbox;
+GtkWidget *label;
 int errorbox_up;
 gint tag;		/* Used by gdk_input_* */
+gint timeo;
+gint res;
+gint to_get;
 
 /*--- globals to this file */
 
@@ -151,7 +155,6 @@
 
 	/* The rest is error handling */
 
-	GtkWidget *label;
 	if (errorbox_up)
 		return(-1); /* ERROR window already onscreen */
 	errbox = gtk_window_new(GTK_WINDOW_DIALOG);
@@ -380,9 +383,9 @@
 	struct pollfd ufds;
 	ufds.fd = source;
 	ufds.events = POLLIN;
-	gint timeo = 100; /* wait 100ms max before timeout */
-	gint res = -1;
-	gint to_get = 0;
+	timeo = 100; /* wait 100ms max before timeout */
+	res = -1;
+	to_get = 0;
      
 	/* reset data ring buffer */
 	ring_pos=0;
