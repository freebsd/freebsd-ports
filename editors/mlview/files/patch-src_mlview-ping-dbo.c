--- src/mlview-ping-dbo.c.orig	Mon Sep  5 12:52:49 2005
+++ src/mlview-ping-dbo.c	Mon Sep  5 12:53:50 2005
@@ -362,13 +362,16 @@
 			0,
 			(GInstanceInitFunc) mlview_ping_dbo_init
 		} ;
-		type = g_type_register_static (G_TYPE_OBJECT,
-				               "MlViewPingDBO",
-					       &type_info, 0) ;
+
 		static const GInterfaceInfo idbo_info = {
 			(GInterfaceInitFunc) mlview_ping_dbo_idbo_init,
 			NULL, NULL
 		} ;
+
+                type = g_type_register_static (G_TYPE_OBJECT,
+                                               "MlViewPingDBO",
+                                               &type_info, 0) ;
+
 		g_type_add_interface_static (type, MLVIEW_TYPE_IDBO,
 					     &idbo_info) ;
 	}
