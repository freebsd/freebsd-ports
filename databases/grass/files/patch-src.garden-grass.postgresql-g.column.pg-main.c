--- src.garden/grass.postgresql/g.column.pg/main.c.orig	Sun Jul 11 17:18:12 2004
+++ src.garden/grass.postgresql/g.column.pg/main.c	Sun Jul 11 17:19:04 2004
@@ -80,24 +80,24 @@
 /* Postgres 6.x style */
 
 	if (flag->answer) {
-		sprintf(SQL, "SELECT a.attname as ColumnName, t.typname as Type,
-		  a.attlen as Length,
-		  a.atttypmod as \"Mod_Length\"
-		 FROM pg_class c, pg_attribute a, pg_type t
-		 WHERE  c.relname = '%s' 
-		  and a.attnum > 0
-		  and a.attrelid = c.oid
-		  and a.atttypid = t.oid
+		sprintf(SQL, "SELECT a.attname as ColumnName, t.typname as Type,\
+		  a.attlen as Length,\
+		  a.atttypmod as \"Mod_Length\"\
+		 FROM pg_class c, pg_attribute a, pg_type t\
+		 WHERE  c.relname = '%s'\
+		  and a.attnum > 0\
+		  and a.attrelid = c.oid\
+		  and a.atttypid = t.oid\
 		  order by attnum", tbl->answer );	
 
 	}
 	else {
 	/* no column descriptions */
-		sprintf(SQL, "SELECT a.attname as ColumnName
-		 FROM pg_class c, pg_attribute a
-		 WHERE  c.relname = '%s' 
-		  and a.attnum > 0
-		  and a.attrelid = c.oid
+		sprintf(SQL, "SELECT a.attname as ColumnName\
+		 FROM pg_class c, pg_attribute a\
+		 WHERE  c.relname = '%s'\
+		  and a.attnum > 0\
+		  and a.attrelid = c.oid\
 		  order by attnum", tbl->answer );		
 	}
 
