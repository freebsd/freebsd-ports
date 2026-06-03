--- tools/browser/browser-virtual-connection.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/browser-virtual-connection.c
@@ -489,7 +489,7 @@ browser_virtual_connection_part_copy (const BrowserVir
 		if (spm->table_name)
 			npm->table_name = g_strdup (spm->table_name);
 		if (spm->model)
-			npm->model = g_object_ref (G_OBJECT (spm->model));
+			npm->model = (GdaDataModel *) g_object_ref (G_OBJECT (spm->model));
 		break;
 	}
 	case BROWSER_VIRTUAL_CONNECTION_PART_CNC: {
@@ -500,7 +500,7 @@ browser_virtual_connection_part_copy (const BrowserVir
 		if (scnc->table_schema)
 			ncnc->table_schema = g_strdup (scnc->table_schema);
 		if (scnc->source_cnc)
-			ncnc->source_cnc = g_object_ref (G_OBJECT (scnc->source_cnc));
+			ncnc->source_cnc = (BrowserConnection *) g_object_ref (G_OBJECT (scnc->source_cnc));
 		break;
 	}
 	default:
