--- libgda/gda-util.c.orig	Sat Jul 17 11:02:21 2004
+++ libgda/gda-util.c	Sat Jul 17 11:03:07 2004
@@ -60,7 +60,7 @@
 	case GDA_VALUE_TYPE_TIME : return "time";
 	case GDA_VALUE_TYPE_TIMESTAMP : return "timestamp";
 	case GDA_VALUE_TYPE_TINYINT : return "tinyint";
-	default:
+	default: ;
 	}
 
 	return "string";
