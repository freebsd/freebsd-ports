--- providers/oracle/utils.c~	Wed Mar 15 07:25:51 2006
+++ providers/oracle/utils.c	Sun Mar 26 10:20:18 2006
@@ -415,7 +415,7 @@
 		g_free (string_buffer);
 		break;
 	case GDA_VALUE_TYPE_BIGINT:
-		gda_value_set_bigint (value, atoll (ora_value->value));
+		gda_value_set_bigint (value, strtoll (ora_value->value, (char **)NULL, 10));
 		break;
 	case GDA_VALUE_TYPE_INTEGER:
 		gda_value_set_integer (value, atol (ora_value->value));
