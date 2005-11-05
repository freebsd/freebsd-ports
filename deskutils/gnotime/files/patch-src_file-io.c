--- src/file-io.c.orig	Fri Oct 21 06:49:42 2005
+++ src/file-io.c	Fri Oct 21 06:50:50 2005
@@ -513,7 +513,7 @@ void
 gtt_load_config (void)
 {
 	const char *h;
-	char * s;
+	char * s, * p;
 
 	/* Check for gconf2, and use that if it exists */
 	if (gtt_gconf_exists())
@@ -532,7 +532,7 @@ gtt_load_config (void)
 
 		/* The data file will be in the same directory ...
 		 * so prune filename to get the directory */
-		char *p = strrchr (gtt_config_filepath, '/');
+		p = strrchr (gtt_config_filepath, '/');
 		if (p) *p = 0x0;
  		return;
  	}
