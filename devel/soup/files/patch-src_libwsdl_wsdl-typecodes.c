--- src/libwsdl/wsdl-typecodes.c.orig	Fri Aug 13 13:17:44 2004
+++ src/libwsdl/wsdl-typecodes.c	Fri Aug 13 13:18:45 2004
@@ -977,7 +977,7 @@
 {
 	switch (tc->kind) {
 	case WSDL_TK_GLIB_NULL:
-		g_warning ("Invalid typecode NULL in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode NULL in %s",G_GNUC_FUNCTION);
 		return (0);
 		break;
 
@@ -1082,7 +1082,7 @@
 		break;
 
 	case WSDL_TK_GLIB_MAX:
-		g_warning ("Invalid typecode MAX in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode MAX in %s",G_GNUC_FUNCTION);
 		return (0);
 		break;
 	}
@@ -1106,7 +1106,7 @@
 {
 	switch (tc->kind) {
 	case WSDL_TK_GLIB_NULL:
-		g_warning ("Invalid typecode NULL in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode NULL in %s",G_GNUC_FUNCTION);
 		return (0);
 		break;
 
@@ -1218,7 +1218,7 @@
 		break;
 
 	case WSDL_TK_GLIB_MAX:
-		g_warning ("Invalid typecode MAX in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode MAX in %s",G_GNUC_FUNCTION);
 		return (0);
 		break;
 	}
