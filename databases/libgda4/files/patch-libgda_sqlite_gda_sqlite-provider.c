Index: libgda/sqlite/gda-sqlite-provider.c
===================================================================
--- libgda/sqlite/gda-sqlite-provider.c	(revision 3276)
+++ libgda/sqlite/gda-sqlite-provider.c	(working copy)
@@ -404,7 +404,7 @@
 		/* It's a function */
 		recset = (GdaDataModelArray *) cdata->functions_model;
 		if (!recset) {
-			recset = GDA_DATA_MODEL_ARRAY (gda_data_model_array_new, 3);
+			recset = GDA_DATA_MODEL_ARRAY (gda_data_model_array_new (3));
 			gda_column_set_description (0, "name");
 			gda_column_set_name (0, "name");
 			gda_column_set_g_type (0, G_TYPE_STRING);
@@ -422,7 +422,7 @@
 		/* It's an aggregate */
 		recset = (GdaDataModelArray *) cdata->aggregates_model;
 		if (!recset) {
-			recset = GDA_DATA_MODEL_ARRAY (gda_data_model_array_new, 3);
+			recset = GDA_DATA_MODEL_ARRAY (gda_data_model_array_new (3));
 			gda_column_set_description (0, "name");
 			gda_column_set_name (0, "name");
 			gda_column_set_g_type (0, G_TYPE_STRING);
