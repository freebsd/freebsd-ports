--- src/mlview-source-view.c.orig	Mon Sep  5 12:24:55 2005
+++ src/mlview-source-view.c	Mon Sep  5 12:25:47 2005
@@ -1321,15 +1321,17 @@
                         (GInstanceInitFunc)
                         mlview_source_view_init
                 } ;
-                type = g_type_register_static
-                        (MLVIEW_TYPE_VIEW_ADAPTER,
-                         "MlViewSourceView", &type_info, 0);
 
 		static const GInterfaceInfo iview_info = {
 			(GInterfaceInitFunc) mlview_source_view_iview_init,
 			NULL,
 			NULL
 		} ;
+
+		type = g_type_register_static
+                        (MLVIEW_TYPE_VIEW_ADAPTER,
+			 "MlViewSourceView", &type_info, 0);
+
 		g_type_add_interface_static (type, MLVIEW_TYPE_IVIEW,
 		                             &iview_info) ;
         }
