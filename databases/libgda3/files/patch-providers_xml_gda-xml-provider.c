--- providers/xml/gda-xml-provider.c.orig	Sat Jul 17 11:05:02 2004
+++ providers/xml/gda-xml-provider.c	Sat Jul 17 11:05:11 2004
@@ -681,7 +681,7 @@
 		return get_tables (cnc, xmldb);
 	case GDA_CONNECTION_SCHEMA_TYPES :
 		return get_types (cnc);
-	default :
+	default : ;
 	}
 
 	return NULL;
