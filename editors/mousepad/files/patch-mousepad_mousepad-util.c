--- mousepad/mousepad-util.c.orig	2014-09-01 20:50:07 UTC
+++ mousepad/mousepad-util.c
@@ -1063,7 +1063,7 @@ mousepad_util_search (GtkTextBuffer       *buffer,
 GtkAction *
 mousepad_util_find_related_action (GtkWidget *widget)
 {
-  GtkAction *action;
+  GtkAction *action = NULL;
 
   g_return_val_if_fail (GTK_IS_WIDGET (widget), NULL);
 
