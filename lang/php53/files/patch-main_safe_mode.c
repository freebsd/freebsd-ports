--- main/safe_mode.c.orig	2008-09-04 15:52:19.000000000 +0200
+++ main/safe_mode.c	2008-09-04 15:52:35.000000000 +0200
@@ -74,14 +74,6 @@
 		}
 	}
 
-	/* 
-	 * If given filepath is a URL, allow - safe mode stuff
-	 * related to URL's is checked in individual functions
-	 */
-	wrapper = php_stream_locate_url_wrapper(filename, NULL, STREAM_LOCATE_WRAPPERS_ONLY TSRMLS_CC);
-	if (wrapper != NULL)
-		return 1;
-		
 	/* First we see if the file is owned by the same user...
 	 * If that fails, passthrough and check directory...
 	 */
