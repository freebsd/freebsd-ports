--- ./bandb/rsdb_sqlite3.c.orig	2008-11-15 02:59:20.000000000 +0000
+++ ./bandb/rsdb_sqlite3.c	2008-11-15 02:59:59.000000000 +0000
@@ -58,18 +58,13 @@
 int
 rsdb_init(rsdb_error_cb * ecb)
 {
-	const char *bandb_dpath;
 	char dbpath[PATH_MAX];
 	char errbuf[128];
 	error_cb = ecb;
 
-	/* try a path from the environment first, useful for basedir overrides */
-	bandb_dpath = getenv("BANDB_DPATH");
-
-	if(bandb_dpath != NULL)
-		rb_snprintf(dbpath, sizeof(dbpath), "%s/etc/ban.db", bandb_dpath);
-	else
-		rb_strlcpy(dbpath, DBPATH, sizeof(dbpath));
+	/* remove the getenv checks and just use the DBPATH value so bandb
+	gets the right value for fbsd ban.db locateion. */
+	rb_strlcpy(dbpath, DBPATH, sizeof(dbpath));
 	
 	if(sqlite3_open(dbpath, &rb_bandb) != SQLITE_OK)
 	{
