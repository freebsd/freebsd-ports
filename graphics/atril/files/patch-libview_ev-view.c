--- libview/ev-view.c.orig	2014-02-21 19:08:58.000000000 +0100
+++ libview/ev-view.c	2014-02-21 19:09:45.000000000 +0100
@@ -840,6 +840,7 @@
 }
 
 #if !GTK_CHECK_VERSION (3, 0, 0)
+static void
 ev_view_set_scroll_adjustments (GtkLayout      *layout,
 				GtkAdjustment  *hadjustment,
 				GtkAdjustment  *vadjustment)
