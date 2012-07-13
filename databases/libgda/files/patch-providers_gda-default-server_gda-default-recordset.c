--- providers/gda-default-server/gda-default-recordset.c.orig	2012-06-24 18:51:52.000000000 +0200
+++ providers/gda-default-server/gda-default-recordset.c	2012-06-24 18:52:59.000000000 +0200
@@ -115,7 +115,7 @@
 {
 	DEFAULT_Recordset *default_recset;
 
-	g_return_if_fail(recset != NULL);
+	g_return_val_if_fail(recset != NULL, -1);
 
 	default_recset = (DEFAULT_Recordset *) gda_server_recordset_get_user_data(recset);
 	if (default_recset) {