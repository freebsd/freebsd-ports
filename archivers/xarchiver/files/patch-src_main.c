--- src/main.c.orig	2025-09-01 12:04:54 UTC
+++ src/main.c
@@ -478,7 +478,7 @@ static void xa_check_available_archivers ()
 	/* GNU zip */
 
 	type = XARCHIVETYPE_GZIP;
-	path = g_find_program_in_path("gzip");
+	path = g_find_program_in_path("%%LOCALBASE%%/bin/gzip");
 
 	if (path)
 		archiver[type].is_compressor = TRUE;
@@ -1014,11 +1014,11 @@ static void xa_check_available_archivers ()
 	if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(prefs_window->prefer_unzip)) ||
 	    (!is7za && !lsar))
 	{
-		path = g_find_program_in_path("unzip");
+		path = g_find_program_in_path("%%LOCALBASE%%/bin/unzip");
 
 		if (path)
 		{
-			gchar *zip = g_find_program_in_path("zip");
+			gchar *zip = g_find_program_in_path("%%LOCALBASE%%/bin/zip");
 
 			if (zip)
 			{
