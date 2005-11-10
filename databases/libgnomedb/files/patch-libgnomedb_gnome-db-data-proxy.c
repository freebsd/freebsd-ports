
$FreeBSD$

--- libgnomedb/gnome-db-data-proxy.c.orig
+++ libgnomedb/gnome-db-data-proxy.c
@@ -1272,10 +1272,10 @@
 void
 gnome_db_data_proxy_reset_all (GnomeDbDataProxy *proxy)
 {
-	g_return_if_fail (proxy && IS_GNOME_DB_DATA_PROXY (proxy));
-	g_return_if_fail (proxy->priv);
 	GtkTreePath *path;
 	GtkTreeIter iter;
+	g_return_if_fail (proxy && IS_GNOME_DB_DATA_PROXY (proxy));
+	g_return_if_fail (proxy->priv);
 
 	/* new rows are first treated and removed (no memory de-allocation here, though) */
 	if (proxy->priv->new_rows) {
