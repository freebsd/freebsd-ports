--- libgda/handlers/gda-handler-numerical.c~	Mon Jan 23 02:57:38 2006
+++ libgda/handlers/gda-handler-numerical.c	Sun Mar 26 10:18:42 2006
@@ -231,7 +231,7 @@
 
 	switch (type) {
 	case GDA_VALUE_TYPE_BIGINT:
-		value = gda_value_new_bigint (atoll (str));
+		value = gda_value_new_bigint (strtoll (str, (char **)NULL, 10));
 		break;
 	case GDA_VALUE_TYPE_DOUBLE:
 		value = gda_value_new_double (atof (str));
