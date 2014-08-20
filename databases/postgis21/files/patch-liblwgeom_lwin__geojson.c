--- liblwgeom/lwin_geojson.c.orig	2014-08-20 10:32:15.721407424 +0600
+++ liblwgeom/lwin_geojson.c	2014-08-20 10:32:44.823412267 +0600
@@ -17,8 +17,8 @@
 
 #ifdef HAVE_LIBJSON
 
-#include <json/json.h>
-#include <json/json_object_private.h>
+#include <json-c/json.h>
+#include <json-c/json_object_private.h>
 #include <string.h>
 
 static void geojson_lwerror(char *msg, int error_code)
@@ -510,7 +510,7 @@
 	if( jstok->err != json_tokener_success)
 	{
 		char err[256];
-		snprintf(err, 256, "%s (at offset %d)", json_tokener_errors[jstok->err], jstok->char_offset);
+		snprintf(err, 256, "%s (at offset %d)", json_tokener_error_desc(jstok->err), jstok->char_offset);
 		json_tokener_free(jstok);
     json_object_put(poObj);
 		geojson_lwerror(err, 1);
