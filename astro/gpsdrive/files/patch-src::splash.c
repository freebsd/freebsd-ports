--- src/splash.c.orig	Mon Jun  7 09:55:30 2004
+++ src/splash.c	Mon Jun  7 09:56:28 2004
@@ -529,6 +529,24 @@
 {
   GtkTextIter iter;
   GtkTextIter start, end;
+  gchar *t1 =
+    _
+    ("Left mouse button         : Set position (usefull in simulation mode)\n"
+     "Right mouse button        : Set target directly on the map\n"
+     "Middle mouse button       : Display position again\n"
+     "Shift left mouse button   : smaller map\n"
+     "Shift right mouse button  : larger map\n"
+     "Control left mouse button : Set a waypoint (mouse position) on the map\n"
+     "Control right mouse button: Set a waypoint at current position on the map\n\n");
+  gchar *t2 = _("j    : switch to next waypoint in route mode\n"
+		"x    : add waypoint at current position\n"
+		"y    : add waypoint at mouse cursor position\n");
+  gchar *t3 =
+    _("Press the underlined key together with the ALT-key.\n\n"
+      "You can move on the map by selecting the Position-Mode"
+      " in the menu. A blue rectangle shows this mode, you can set this cursor by clicking on the map."
+      " If you click on the border of the map (the outer 20%) then the map switches to the next area.\n\n"
+      "Suggestions welcome.\n\n");
 
   /* demo_find_file() looks in the the current directory first,
    * so you can run gtk-demo without installing GTK, then looks
@@ -564,19 +582,7 @@
 					    -1, "blue_foreground", NULL);
 
   gtk_text_buffer_insert (buffer, &iter, "\n", -1);
-  gchar *t1 =
-    _
-    ("Left mouse button         : Set position (usefull in simulation mode)\n"
-     "Right mouse button        : Set target directly on the map\n"
-     "Middle mouse button       : Display position again\n"
-     "Shift left mouse button   : smaller map\n"
-     "Shift right mouse button  : larger map\n"
-     "Control left mouse button : Set a waypoint (mouse position) on the map\n"
-     "Control right mouse button: Set a waypoint at current position on the map\n\n");
 
-  gchar *t2 = _("j    : switch to next waypoint in route mode\n"
-		"x    : add waypoint at current position\n"
-		"y    : add waypoint at mouse cursor position\n");
   gtk_text_buffer_insert (buffer, &iter, t1, -1);
 
   gtk_text_buffer_insert_with_tags_by_name (buffer, &iter,
@@ -592,12 +598,6 @@
 					    -1, "underline", NULL);
   gtk_text_buffer_insert (buffer, &iter, _(" letters in the button text.\n"),
 			  -1);
-  gchar *t3 =
-    _("Press the underlined key together with the ALT-key.\n\n"
-      "You can move on the map by selecting the Position-Mode"
-      " in the menu. A blue rectangle shows this mode, you can set this cursor by clicking on the map."
-      " If you click on the border of the map (the outer 20%) then the map switches to the next area.\n\n"
-      "Suggestions welcome.\n\n");
   gtk_text_buffer_insert (buffer, &iter, t3, -1);
   gtk_text_buffer_insert_with_tags_by_name (buffer, &iter,
 					    _("Have a lot of fun!"), -1,
