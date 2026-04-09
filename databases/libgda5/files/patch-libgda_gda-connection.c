--- libgda/gda-connection.c.orig	2020-11-08 20:23:19 UTC
+++ libgda/gda-connection.c
@@ -6458,7 +6458,7 @@ gda_connection_add_prepared_statement (GdaConnection *
 
 	if (!cnc->priv->prepared_stmts)
 		cnc->priv->prepared_stmts = g_hash_table_new_full (g_direct_hash, g_direct_equal,
-								   NULL, _gda_prepared_estatement_free);
+								   NULL, (GDestroyNotify) _gda_prepared_estatement_free);
 	g_hash_table_remove (cnc->priv->prepared_stmts, gda_stmt);
 	PreparedStatementRef *ref = _gda_prepared_estatement_new (gda_stmt, prepared_stmt);
 	g_hash_table_insert (cnc->priv->prepared_stmts, gda_stmt, ref);
