--- providers/mdb/gda-mdb-provider.c.orig	Sat Jul 17 11:05:48 2004
+++ providers/mdb/gda-mdb-provider.c	Sat Jul 17 11:06:12 2004
@@ -389,7 +389,7 @@
 			g_strfreev (arr);
 		}
 		break;
-	default :
+	default : ;
 	}
 
 	return reclist;
@@ -438,7 +438,7 @@
 	case GDA_CONNECTION_FEATURE_PROCEDURES :
 	case GDA_CONNECTION_FEATURE_SQL :
 		return TRUE;
-	default :
+	default : ;
 	}
 
 	return FALSE;
