--- src/AC3DPlugins/obj8_import.cpp.orig	2018-07-05 08:49:54 UTC
+++ src/AC3DPlugins/obj8_import.cpp
@@ -503,7 +503,7 @@ ACObject *	do_obj8_load(char *filename)
 				panel_get_import_scaling(panel_id,last_reg,&s_mul,&t_mul,&s_add,&t_add);
 				break;
 			case attr_No_Blend:
-				if (!no_blend != cmd->params[0]) stuff_obj = NULL;
+				if ((!no_blend) != cmd->params[0]) stuff_obj = NULL;
 				no_blend = cmd->params[0];
 				break;
 			case attr_Blend:
