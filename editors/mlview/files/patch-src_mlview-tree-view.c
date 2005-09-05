--- src/mlview-tree-view.c.orig	Mon Sep  5 12:22:34 2005
+++ src/mlview-tree-view.c	Mon Sep  5 12:24:10 2005
@@ -2628,15 +2628,17 @@
                         (GInstanceInitFunc)
                         mlview_tree_view_init
                 };                
-                type = g_type_register_static
-                        (MLVIEW_TYPE_VIEW_ADAPTER,
-                         "MlViewTreeView", &type_info, 0);
 
 		static const GInterfaceInfo iview_info = {
 			(GInterfaceInitFunc) mlview_tree_view_iview_init,
 			NULL,
 			NULL
 		} ;
+
+                type = g_type_register_static
+                        (MLVIEW_TYPE_VIEW_ADAPTER,
+                         "MlViewTreeView", &type_info, 0);
+		
 		g_type_add_interface_static (type, MLVIEW_TYPE_IVIEW, &iview_info) ;
         }
         return type;
