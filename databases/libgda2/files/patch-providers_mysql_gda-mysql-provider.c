--- patch-providers_mysql_gda-mysql-provider.c begins here ---
--- providers/mysql/gda-mysql-provider.c.orig	Sat Aug 14 22:14:57 2004
+++ providers/mysql/gda-mysql-provider.c	Sat Aug 14 22:15:59 2004
@@ -510,7 +510,7 @@
 
 		g_free (str);
 		break;
-	default:
+	default: ;
 	}
 
 	return reclist;
@@ -655,7 +655,7 @@
 	case GDA_CONNECTION_FEATURE_SQL :
 	case GDA_CONNECTION_FEATURE_TRANSACTIONS :
 		return TRUE;
-	default :
+	default : ;
 	}
 
 	return FALSE;
@@ -1187,7 +1187,7 @@
 		return get_mysql_tables (cnc, params);
 	case GDA_CONNECTION_SCHEMA_TYPES :
 		return get_mysql_types (cnc, params);
-	default :
+	default : ;
 	}
 
 	return NULL;
