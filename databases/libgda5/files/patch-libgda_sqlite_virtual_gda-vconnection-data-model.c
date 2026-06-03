--- libgda/sqlite/virtual/gda-vconnection-data-model.c.orig	2020-11-08 20:23:20 UTC
+++ libgda/sqlite/virtual/gda-vconnection-data-model.c
@@ -632,7 +632,7 @@ _gda_vconnection_set_working_obj (GdaVconnectionDataMo
 			VContext *vc = NULL;
 			
 			g_assert (!td->context.current_vcontext);
-			td->context.mutex = &(cnc->priv->lock_context);
+			td->context.mutex = (GMutex *) &(cnc->priv->lock_context);
 			if (! td->context.hash)
 				td->context.hash = g_hash_table_new_full (g_direct_hash, g_direct_equal,
 									  NULL, (GDestroyNotify) vcontext_free);
