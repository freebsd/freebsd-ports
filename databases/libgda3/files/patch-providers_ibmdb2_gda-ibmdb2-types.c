--- providers/ibmdb2/gda-ibmdb2-types.c~	Thu Jan 12 07:10:33 2006
+++ providers/ibmdb2/gda-ibmdb2-types.c	Sun Mar 26 10:19:26 2006
@@ -115,7 +115,7 @@
 				gda_value_set_integer (value, *((gint*)field->column_data));
 				break;
 			case SQL_BIGINT:
-				gda_value_set_bigint (value, (gint64)atoll(field->column_data));
+				gda_value_set_bigint (value, (gint64)strtoll(field->column_data, (char **)NULL, 10));
 				break;
 			case SQL_REAL:
 				gda_value_set_single (value, *((gfloat*)field->column_data));
