--- src/mlview-ping-dbc.c.orig	Mon Sep  5 12:57:39 2005
+++ src/mlview-ping-dbc.c	Mon Sep  5 12:58:35 2005
@@ -166,14 +166,16 @@
 			0,
 			(GInstanceInitFunc) mlview_ping_dbc_init
 		} ;
-		type = g_type_register_static (G_TYPE_OBJECT,
-				               "MlViewPingDBC",
-					       &type_info, 0) ;
 
 		static const GInterfaceInfo idbc_info = {
 			(GInterfaceInitFunc) mlview_ping_dbc_idbc_init,
 			NULL, NULL
 		} ;
+
+                type = g_type_register_static (G_TYPE_OBJECT,
+                                               "MlViewPingDBC",
+                                               &type_info, 0) ;
+
 		g_type_add_interface_static (type, MLVIEW_TYPE_IDBC,
 				             &idbc_info) ;
 	}
