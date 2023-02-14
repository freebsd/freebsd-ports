--- src/bubble-window.c.orig	2012-03-23 14:49:59 UTC
+++ src/bubble-window.c
@@ -78,8 +78,8 @@ bubble_window_get_accessible (GtkWidget *widget)
     {
       AtkObjectFactory *factory = NULL;
       AtkRegistry *registry = NULL;
-      GType derived_type = NULL;
-      GType derived_atk_type = NULL;
+      GType derived_type = G_TYPE_NONE;
+      GType derived_atk_type = ATK_TYPE_OBJECT;
 
       /*
        * Figure out whether accessibility is enabled by looking at the
