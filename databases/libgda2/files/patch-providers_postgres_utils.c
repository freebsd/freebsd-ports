--- providers/postgres/utils.c.orig	Mon Feb 17 21:43:51 2003
+++ providers/postgres/utils.c	Mon Feb 17 21:44:12 2003
@@ -156,7 +156,7 @@
 		gda_value_set_string (value, thevalue);
 		break;
 	case GDA_VALUE_TYPE_BIGINT :
-		gda_value_set_bigint (value, atoll (thevalue));
+		gda_value_set_bigint (value, strtoll(thevalue, &thevalue, 10));
 		break;
 	case GDA_VALUE_TYPE_INTEGER :
 		gda_value_set_integer (value, atol (thevalue));
