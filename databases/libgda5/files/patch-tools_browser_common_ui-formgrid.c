--- tools/browser/common/ui-formgrid.c.orig	2020-11-08 20:23:20 UTC
+++ tools/browser/common/ui-formgrid.c
@@ -754,11 +754,11 @@ statement_executed_cb (G_GNUC_UNUSED BrowserConnection
 				ui_formgrid_handle_user_prefs (UI_FORMGRID (fg), NULL, stmt);
 				g_object_unref (stmt);
 			}
-			aed->model = g_object_ref (out_result);
+			aed->model = (GdaDataModel *) g_object_ref (out_result);
 			g_signal_connect (aed->params, "holder-changed",
 					  G_CALLBACK (action_executed_holder_changed_cb), aed);
 
-			aed->formgrid = g_object_ref (fg);
+			aed->formgrid = (UiFormGrid *) g_object_ref (fg);
 			aed->formgrid->priv->autoupdate_possible = TRUE;
 			gtk_widget_show (aed->formgrid->priv->autoupdate_toggle);
 		}
