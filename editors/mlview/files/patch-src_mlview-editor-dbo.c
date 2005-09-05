--- src/mlview-editor-dbo.c.orig	Mon Sep  5 12:50:28 2005
+++ src/mlview-editor-dbo.c	Mon Sep  5 12:51:41 2005
@@ -303,14 +303,16 @@
 			0,
 			(GInstanceInitFunc) mlview_editor_dbo_init
 		} ;
-		type = g_type_register_static (G_TYPE_OBJECT,
-				               "MlViewEditorDBO",
-					       &type_info, 0) ;
 
 		static const GInterfaceInfo idbo_info = {
 			(GInterfaceInitFunc) mlview_editor_dbo_idbo_init,
 			NULL, NULL
 		} ;
+
+                type = g_type_register_static (G_TYPE_OBJECT,
+                                               "MlViewEditorDBO",
+                                               &type_info, 0) ;
+
 		g_type_add_interface_static (type, MLVIEW_TYPE_IDBO,
 				             &idbo_info) ;
 	}
