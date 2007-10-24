--- gnobots2/properties.c.orig	2007-09-07 15:39:29.000000000 -0500
+++ gnobots2/properties.c	2007-09-07 15:41:56.000000000 -0500
@@ -116,6 +116,7 @@
 static void defkey_cb (GtkWidget *, gpointer);
 static void fill_typemenu (GtkWidget *);
 static void conf_set_background_color (GdkColor * c);
+static void load_keys (void);
 /**********************************************************************/
 
 
