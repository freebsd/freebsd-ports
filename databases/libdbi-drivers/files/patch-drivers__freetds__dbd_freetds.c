--- ./drivers/freetds/dbd_freetds.c.orig	2007-12-31 14:10:44.000000000 -0800
+++ ./drivers/freetds/dbd_freetds.c	2009-07-20 01:30:00.373376559 -0700
@@ -454,6 +454,7 @@
 {
     dbi_result_t *res;
     char *sql_cmd;
+    char *current_db = NULL;
 
     if (db == NULL || db[0] == '\0') {
 	/* Use current database */
@@ -461,7 +462,6 @@
 	return res;
     }
 
-    char *current_db = NULL;
     if (conn->current_db)
 	/* Reserved current DB name */
 	current_db = strdup(conn->current_db);
@@ -509,9 +509,9 @@
 {
     /* foo's -> 'foo''s' */
     size_t len;
+    const char *escaped = "\'";
 
     strcpy(dest, "\'");
-    const char *escaped = "\'";
 
     len = _dbd_freetds_escape_chars(dest + 1, orig, strlen(orig), escaped);
 
@@ -560,6 +560,8 @@
      * everything else will be filled in by DBI */
 
     unsigned int idx = 0;
+    unsigned short type = 0;
+    unsigned int attribs = 0;
     dbi_result_t *result = NULL;
     dbi_row_t *row = NULL;
     FREETDSCON *tdscon = (FREETDSCON *) conn->connection;
@@ -629,9 +631,6 @@
 		    return NULL;
 		}
 
-		unsigned short type = 0;
-		unsigned int attribs = 0;
-
 		_translate_freetds_type(datafmt[idx], &type, &attribs);
 		/* Fill fields value in result */
 		_dbd_result_add_field(result, idx, datafmt[idx]->name, type, attribs);
@@ -885,6 +884,7 @@
     dbi_row_t *row = NULL;
     unsigned int idx = 0;
     void *addr = NULL;
+    char **orig;
 
     FREETDSCON *tdscon = (FREETDSCON *) conn->connection;
 
@@ -912,8 +912,7 @@
 		    dstfmt.format = CS_FMT_UNUSED;
 
 		    addr = malloc(sizeof(CS_NUMERIC_TYPE));
-		    char **orig =
-			&(result->rows[result->numrows_matched]->field_values[idx].d_string);
+		    orig = &(result->rows[result->numrows_matched]->field_values[idx].d_string);
 
 		    if (cs_convert(tdscon->ctx, datafmt[idx], *orig, &dstfmt, addr, NULL) !=
 			CS_SUCCEED) {
