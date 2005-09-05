--- src/mlview-view-adapter.c.orig	Mon Sep  5 12:19:12 2005
+++ src/mlview-view-adapter.c	Mon Sep  5 12:21:26 2005
@@ -865,14 +865,17 @@
                         (GInstanceInitFunc)
                         mlview_view_adapter_init
                 };
-                type_id = g_type_register_static (GTK_TYPE_VBOX,
-                                                  "MlViewViewAdapter",
-                                                  &type_info, 0);
+
 		static const GInterfaceInfo iview_info = {
 			(GInterfaceInitFunc) mlview_view_adapter_iview_init,
 			NULL,
 			NULL
 		} ;
+
+                type_id = g_type_register_static (GTK_TYPE_VBOX,
+		                                  "MlViewViewAdapter",
+						  &type_info, 0);
+
 		g_type_add_interface_static (type_id, MLVIEW_TYPE_IVIEW,
 		                             &iview_info) ;
         }
