--- server/gam_node.h.orig	2011-09-17 11:19:43.000000000 +0200
+++ server/gam_node.h	2011-09-17 11:20:13.000000000 +0200
@@ -58,7 +58,7 @@ gboolean              gam_node_is_dir   
 void                  gam_node_set_is_dir          (GamNode         *node,
 						   gboolean        is_dir);
 	
-G_CONST_RETURN char  *gam_node_get_path            (GamNode         *node);
+const char           *gam_node_get_path            (GamNode         *node);
 
 GList                *gam_node_get_subscriptions   (GamNode         *node);
 
