--- providers/mysql/gda-mysql-recordset.c.orig	Mon Feb 17 21:42:16 2003
+++ providers/mysql/gda-mysql-recordset.c	Mon Feb 17 21:42:57 2003
@@ -102,7 +102,7 @@
 			break;
 		case FIELD_TYPE_LONGLONG :
 		case FIELD_TYPE_INT24 :
-			gda_value_set_bigint (field, thevalue ? atoll (thevalue) : 0);
+			gda_value_set_bigint (field, thevalue ? strtoll(thevalue, &thevalue, 10) : 0);
 			break;
 		case FIELD_TYPE_SHORT :
 			gda_value_set_smallint (field, thevalue ? atoi (thevalue) : 0);
