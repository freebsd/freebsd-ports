--- providers/sqlite/gda-sqlite-provider.c.orig	Sat Jul 17 11:09:00 2004
+++ providers/sqlite/gda-sqlite-provider.c	Sat Jul 17 11:09:07 2004
@@ -623,7 +623,7 @@
 	case GDA_CONNECTION_FEATURE_TRIGGERS :
 	case GDA_CONNECTION_FEATURE_VIEWS :
 		return TRUE;
-	default:
+	default: ;
 	}
 
 	return FALSE;
@@ -809,7 +809,7 @@
 		return get_tables (cnc);
 	case GDA_CONNECTION_SCHEMA_TYPES :
 		return get_types ();
-	default:
+	default: ;
 	}
 
 	return NULL;
