--- providers/mysql/gda-mysql-recordset.c.orig	Wed May 18 03:10:04 2005
+++ providers/mysql/gda-mysql-recordset.c	Tue Jun 14 23:12:25 2005
@@ -71,7 +71,7 @@ fill_gda_value (GdaValue *gda_value, enu
 		if (is_unsigned) {
 			gda_value_set_biguint (gda_value, strtoull (value, NULL, 0));
 		} else {
-			gda_value_set_bigint (gda_value, atoll (value));
+			gda_value_set_bigint (gda_value, strtoll (value, NULL, 10));
 		}
 		break;
 	case FIELD_TYPE_SHORT :
