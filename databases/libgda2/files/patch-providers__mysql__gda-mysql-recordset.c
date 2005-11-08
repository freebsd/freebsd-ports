--- ../../work-/libgda-1.9.100/providers/mysql/gda-mysql-recordset.c	Tue Nov  8 14:56:45 2005
+++ providers/mysql/gda-mysql-recordset.c	Tue Nov  8 14:59:26 2005
@@ -569,6 +569,7 @@
 	     colnum != gda_data_model_get_n_columns (GDA_DATA_MODEL(model));
 	     colnum++)
 	{
+		gchar *curval;
 		attrs = gda_data_model_describe_column (GDA_DATA_MODEL(model), colnum);
 
 		mysql_field = mysql_fetch_field_direct (priv_data->mysql_res, colnum);
@@ -577,7 +578,7 @@
 		else
 			column_name = gda_data_model_get_column_title (GDA_DATA_MODEL (model), colnum);
 
-		gchar *curval = gda_mysql_provider_value_to_sql_string (
+		curval = gda_mysql_provider_value_to_sql_string (
 				NULL, 	 
 				priv_data->cnc, 	 
 				gda_row_get_value ((GdaRow *) row, colnum) 	 
