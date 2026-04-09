--- tools/browser/schema-browser/table-info.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/schema-browser/table-info.c
@@ -621,7 +621,7 @@ fk_bind_select_executed_cb (G_GNUC_UNUSED BrowserConne
 			}
 		}
 	}
-	fkdata->model = g_object_ref (out_result);
+	fkdata->model = (GdaDataModel *) g_object_ref (out_result);
 	fkdata->model_rerunning = FALSE;
 }
 
