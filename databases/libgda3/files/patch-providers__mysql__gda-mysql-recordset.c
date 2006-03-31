--- providers/mysql/gda-mysql-recordset.c.orig	Thu Mar  2 22:28:54 2006
+++ providers/mysql/gda-mysql-recordset.c	Sun Mar 26 10:20:02 2006
@@ -141,7 +141,7 @@
 		if (is_unsigned) {
 			gda_value_set_biguint (gda_value, strtoull (value, NULL, 0));
 		} else {
-			gda_value_set_bigint (gda_value, atoll (value));
+			gda_value_set_bigint (gda_value, strtoll (value, (char **)NULL, 0));
 		}
 		break;
 	case FIELD_TYPE_SHORT :
@@ -584,6 +584,7 @@
 	     colnum != gda_data_model_get_n_columns (GDA_DATA_MODEL(model));
 	     colnum++)
 	{
+		gchar *curval;
 		attrs = gda_data_model_describe_column (GDA_DATA_MODEL(model), colnum);
 
 		mysql_field = mysql_fetch_field_direct (priv_data->mysql_res, colnum);
@@ -592,7 +593,7 @@
 		else
 			column_name = gda_data_model_get_column_title (GDA_DATA_MODEL (model), colnum);
 
-		gchar *curval = gda_mysql_provider_value_to_sql_string (
+		curval = gda_mysql_provider_value_to_sql_string (
 				NULL, 	 
 				priv_data->cnc, 	 
 				gda_row_get_value ((GdaRow *) row, colnum) 	 
