diff -ru dbdimp.c~ dbdimp.c
--- dbdimp.c~	Sun Jan  2 20:01:43 2005
+++ dbdimp.c	Sun Jan  2 20:06:16 2005
@@ -986,7 +986,9 @@
 	int num_fields;
 	char *value;
 	char *p;
-	int i, pg_type, value_len, chopblanks, len;
+	int i, pg_type, chopblanks;
+	size_t value_len;
+	STRLEN len;
 	AV *av;
 	D_imp_dbh_from_sth;
 	
