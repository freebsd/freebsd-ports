--- src/seti_applet.c.orig	Thu Mar  6 15:03:55 2003
+++ src/seti_applet.c	Wed Jan 12 22:47:00 2005
@@ -177,6 +177,7 @@
 static void setup_percent_canvas_item(setiapplet *);
 static void setup_units_canvas_item(setiapplet *);
 static void setup_cputime_canvas_item(setiapplet *);
+static void setup_cputime_current_canvas_item(setiapplet *);
 static void applet_change_orient(PanelApplet *,
                                  PanelAppletOrient,
                                  gpointer);
