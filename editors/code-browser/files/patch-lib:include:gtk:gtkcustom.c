--- lib/include/gtk/gtkcustom.c.orig	Mon Jan 31 17:05:27 2005
+++ lib/include/gtk/gtkcustom.c	Mon Jan 31 17:05:43 2005
@@ -131,11 +131,11 @@
 ///////////////////////////////////////////////////////////////////////////////
 static void gtk_custom_add (GtkContainer *container, GtkWidget *widget)
 {
-	g_return_if_fail (GTK_IS_CUSTOM (container));
-	g_return_if_fail (GTK_IS_WIDGET (widget));
-	
 	GtkCustom* custom;
 	GtkCustomChild *child_info;
+	
+	g_return_if_fail (GTK_IS_CUSTOM (container));
+	g_return_if_fail (GTK_IS_WIDGET (widget));
 	
 	custom = GTK_CUSTOM (container);
 	
