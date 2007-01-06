--- providers/mdb/gda-mdb-provider.c.orig	Thu Jan  4 17:14:00 2007
+++ providers/mdb/gda-mdb-provider.c	Thu Jan  4 17:14:06 2007
@@ -209,7 +209,7 @@
 	mdb_cnc = g_new0 (GdaMdbConnection, 1);
 	mdb_cnc->cnc = cnc;
 	mdb_cnc->server_version = NULL;
-	mdb_cnc->mdb = mdb_open (filename, MDB_WRITABLE);
+	mdb_cnc->mdb = mdb_open (filename);
 	if (!mdb_cnc->mdb) {
 		gda_connection_add_error_string (cnc, _("Could not open file %s"), filename);
 		g_free (mdb_cnc);
