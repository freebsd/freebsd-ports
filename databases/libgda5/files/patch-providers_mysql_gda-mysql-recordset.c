--- providers/mysql/gda-mysql-recordset.c.orig	2020-11-08 20:23:20 UTC
+++ providers/mysql/gda-mysql-recordset.c
@@ -627,7 +627,7 @@ gda_mysql_recordset_new (GdaConnection            *cnc
 		/* binding results with types */
 		mysql_bind_result[i].buffer_type = field->type;
 		mysql_bind_result[i].is_unsigned = field->flags & UNSIGNED_FLAG ? TRUE : FALSE;
-		mysql_bind_result[i].is_null = g_malloc0 (sizeof (my_bool));
+		mysql_bind_result[i].is_null = g_malloc0 (sizeof (_Bool));
 		
 		switch (mysql_bind_result[i].buffer_type) {
 		case MYSQL_TYPE_TINY:
@@ -753,7 +753,7 @@ new_row_from_mysql_stmt (GdaMysqlRecordset *imodel, G_
 
 		gint col;
 		for (col = 0; col < ((GdaDataSelect *) imodel)->prep_stmt->ncols; ++col) {
-			my_bool truncated;
+			_Bool truncated;
 			mysql_bind_result[col].error = &truncated;
 			mysql_stmt_fetch_column (imodel->priv->mysql_stmt, &(mysql_bind_result[col]),
 						 (unsigned int)col, 0);
@@ -784,10 +784,10 @@ new_row_from_mysql_stmt (GdaMysqlRecordset *imodel, G_
 		
 		/*g_print ("%s: #%d : TYPE=%d, GTYPE=%s\n", __func__, i, mysql_bind_result[i].buffer_type, g_type_name (type));*/
 
-		my_bool is_null = FALSE;
+		_Bool is_null = FALSE;
 		unsigned long length;
 		
-		memmove (&is_null, mysql_bind_result[i].is_null, sizeof (my_bool));
+		memmove (&is_null, mysql_bind_result[i].is_null, sizeof (_Bool));
 		if (is_null) {
 			gda_value_set_null (value);
 			continue;
