--- src/grip.c.orig	Wed May  1 18:30:22 2002
+++ src/grip.c	Wed May  1 18:30:33 2002
@@ -144,7 +144,7 @@
 
   app=gnome_app_new(PACKAGE,_("Grip"));
 
-  ginfo=g_new(GripInfo,1);
+  ginfo=g_new0(GripInfo,1);
 
   gtk_object_set_user_data(GTK_OBJECT(app),(gpointer)ginfo);
 
