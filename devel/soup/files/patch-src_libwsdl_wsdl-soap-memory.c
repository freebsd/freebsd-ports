--- src/libwsdl/wsdl-soap-memory.c.orig	Fri Aug 13 13:21:36 2004
+++ src/libwsdl/wsdl-soap-memory.c	Fri Aug 13 13:23:14 2004
@@ -33,17 +33,15 @@
 
 	while (param->name != NULL) {
 		if (param->typecode == NULL) {
-			g_warning (G_GNUC_FUNCTION
-				   ": Parameter %s has no typecode!",
-				   param->name);
+			g_warning ("%s: Parameter %s has no typecode!",
+				   G_GNUC_FUNCTION, param->name);
 		} else {
 			if (param->param == NULL) {
-				g_warning (G_GNUC_FUNCTION
-					   ": Parameter %s has no "
+				g_warning ("%s: Parameter %s has no "
 					   "memory location!",
-					   param->name);
+					   G_GNUC_FUNCTION, param->name);
 			} else {
-				memset (param->param, 
+				memset (param->param,
 					'\0',
 					wsdl_typecode_size (param->typecode));
 			}
@@ -71,9 +69,8 @@
 
 	while (param->name != NULL) {
 		if (param->typecode == NULL) {
-			g_warning (G_GNUC_FUNCTION
-				   ": Parameter %s has no typecode!",
-				   param->name);
+			g_warning ("%s: Parameter %s has no typecode!",
+				   G_GNUC_FUNCTION, param->name);
 		} else {
 			if (param->param != NULL &&
 			    *(guchar **) param->param != NULL &&
