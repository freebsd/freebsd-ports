--- src/tX_ladspa.cc.orig	2011-01-30 21:01:31 UTC
+++ src/tX_ladspa.cc
@@ -45,8 +45,8 @@ void LADSPA_Plugin :: init ()
 	ladspa_path_ptr=getenv("LADSPA_PATH");
 	
 	if (!ladspa_path_ptr)  {
-		tX_warning("LADSPA_PATH not set. Trying /usr/lib/ladspa:/usr/local/lib/ladspa");
-		strcpy(ladspa_path, "/usr/lib/ladspa:/usr/local/lib/ladspa");
+		tX_warning("LADSPA_PATH not set. Trying %%LOCALBASE%%/lib/ladspa");
+		strcpy(ladspa_path, "%%LOCALBASE%%/lib/ladspa");
 	}
 	else strncpy(ladspa_path, ladspa_path_ptr, sizeof(ladspa_path));
 	
