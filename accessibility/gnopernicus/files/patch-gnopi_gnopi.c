--- gnopi/gnopi.c.orig	Mon Dec 20 23:47:10 2004
+++ gnopi/gnopi.c	Mon Dec 20 23:48:21 2004
@@ -530,6 +530,7 @@
     GladeXML	*xml    = NULL;
     gint         response_id;
     gboolean     accessibility_on;
+    AtkObject *obj;
     
     /* check if accessibility flag is TRUE */
     accessibility_on = 	gnopiconf_get_bool (ACCESSIBILITY_GCONF_KEY, 
@@ -550,7 +551,7 @@
     
     g_object_unref (G_OBJECT (xml));
     
-    AtkObject *obj = gtk_widget_get_accessible (dialog);
+    obj = gtk_widget_get_accessible (dialog);
     atk_object_set_role (obj, ATK_ROLE_ALERT);
     
     response_id = gtk_dialog_run (GTK_DIALOG (dialog));
@@ -570,7 +571,7 @@
 	
 	g_object_unref (G_OBJECT (xml));
 	
-        AtkObject *obj = gtk_widget_get_accessible (dialog);
+        obj = gtk_widget_get_accessible (dialog);
         atk_object_set_role (obj, ATK_ROLE_ALERT);
         
 	response_id = gtk_dialog_run (GTK_DIALOG (dialog));
