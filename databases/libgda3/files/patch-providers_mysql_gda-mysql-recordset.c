--- providers/mysql/gda-mysql-recordset.c.orig	Thu Jul 22 10:40:31 2004
+++ providers/mysql/gda-mysql-recordset.c	Thu Jul 22 10:42:51 2004
@@ -67,8 +67,8 @@
 	case FIELD_TYPE_LONGLONG :
 	case FIELD_TYPE_INT24 :
 		if (is_unsigned)
-			gda_value_set_biguint (gda_value, atoll (value));
-		gda_value_set_bigint (gda_value, atoll (value));
+			gda_value_set_biguint (gda_value, strtoll (value, &value, 10));
+		gda_value_set_bigint (gda_value, strtoll (value, &value, 10));
 		break;
 	case FIELD_TYPE_SHORT :
 		if (is_unsigned)
