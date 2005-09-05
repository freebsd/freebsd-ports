--- src/mlview-editor-dbc.c.orig	Mon Sep  5 12:55:40 2005
+++ src/mlview-editor-dbc.c	Mon Sep  5 12:56:44 2005
@@ -168,13 +168,16 @@
 			0,
 			(GInstanceInitFunc)mlview_editor_dbc_init
 		} ;
-		type = g_type_register_static (G_TYPE_OBJECT,
-				               "MlViewEditorDBC",
-					       &type_info, 0) ;
+
 		static const GInterfaceInfo idbc_info = {
 			(GInterfaceInitFunc) mlview_editor_dbc_idbc_init,
 			NULL, NULL
 		} ;
+
+                type = g_type_register_static (G_TYPE_OBJECT,
+                                               "MlViewEditorDBC",
+                                               &type_info, 0) ;
+
 		g_type_add_interface_static (type, MLVIEW_TYPE_IDBC,
 				             &idbc_info) ;
 	}
