--- src/main.c.orig	2020-05-30 14:10:55 UTC
+++ src/main.c
@@ -387,7 +387,7 @@ static void xa_check_available_archivers ()
 	/* GNU zip */
 
 	type = XARCHIVETYPE_GZIP;
-	path = g_find_program_in_path("gzip");
+	path = g_find_program_in_path("%%LOCALBASE%%/bin/gzip");
 
 	if (path)
 		archiver[type].is_compressor = TRUE;
@@ -799,11 +799,11 @@ static void xa_check_available_archivers ()
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
