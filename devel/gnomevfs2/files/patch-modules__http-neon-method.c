--- modules/http-neon-method.c.orig	Wed Jan 25 23:15:42 2006
+++ modules/http-neon-method.c	Wed Jan 25 23:17:47 2006
@@ -1908,9 +1908,7 @@
 		}
 	}
 
-
 	result = resolve_result (res, req);	
-	ne_request_destroy (req);
 	
 	if (result == GNOME_VFS_OK) {
 		const char *name;
@@ -1929,6 +1927,8 @@
 		}
 		
 	}
+
+	ne_request_destroy (req);
 
 	return result;
 }
