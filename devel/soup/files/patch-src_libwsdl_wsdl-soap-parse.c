--- src/libwsdl/wsdl-soap-parse.c.orig	Fri Aug 13 13:20:50 2004
+++ src/libwsdl/wsdl-soap-parse.c	Fri Aug 13 13:21:05 2004
@@ -37,7 +37,7 @@
 
 	switch (wsdl_typecode_kind (typecode)) {
 	case WSDL_TK_GLIB_NULL:
-		g_warning ("Invalid typecode NULL in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode NULL in %s",G_GNUC_FUNCTION);
 		break;
 
 	case WSDL_TK_GLIB_VOID:
@@ -203,7 +203,7 @@
 		/* Handled elsewhere */
 		break;
 	case WSDL_TK_GLIB_MAX:
-		g_warning ("Invalid typecode MAX in " G_GNUC_FUNCTION);
+		g_warning ("Invalid typecode MAX in %s",G_GNUC_FUNCTION);
 		break;
 	}
 }
