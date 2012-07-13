--- lib/gda-server/gda-server-connection.c.orig	2012-06-24 18:42:20.000000000 +0200
+++ lib/gda-server/gda-server-connection.c	2012-06-24 18:47:17.000000000 +0200
@@ -247,7 +247,7 @@
 	GdaServerConnection *cnc =
 		(GdaServerConnection *) bonobo_x_object (servant);
 
-	g_return_if_fail (GDA_IS_SERVER_CONNECTION (cnc));
+	g_return_val_if_fail (GDA_IS_SERVER_CONNECTION (cnc), NULL);
 
 	retval = gda_server_connection_create_table (cnc, (GDA_RowAttributes *) columns);
 	if (!retval)
@@ -713,10 +713,10 @@
 gchar *
 gda_server_connection_sql2xml (GdaServerConnection * cnc, const gchar * sql)
 {
-	g_return_if_fail (cnc != NULL);
-	g_return_if_fail (cnc->server_impl != NULL);
-	g_return_if_fail (cnc->server_impl->functions.connection_sql2xml !=
-			  NULL);
+	g_return_val_if_fail (cnc != NULL, NULL);
+	g_return_val_if_fail (cnc->server_impl != NULL, NULL);
+	g_return_val_if_fail (cnc->server_impl->functions.connection_sql2xml !=
+			  NULL, NULL);
 
 	return cnc->server_impl->functions.connection_sql2xml (cnc, sql);
 }
@@ -727,10 +727,10 @@
 gchar *
 gda_server_connection_xml2sql (GdaServerConnection * cnc, const gchar * xml)
 {
-	g_return_if_fail (cnc != NULL);
-	g_return_if_fail (cnc->server_impl != NULL);
-	g_return_if_fail (cnc->server_impl->functions.connection_xml2sql !=
-			  NULL);
+	g_return_val_if_fail (cnc != NULL, NULL);
+	g_return_val_if_fail (cnc->server_impl != NULL, NULL);
+	g_return_val_if_fail (cnc->server_impl->functions.connection_xml2sql !=
+			  NULL, NULL);
 
 	return cnc->server_impl->functions.connection_xml2sql (cnc, xml);
 }
