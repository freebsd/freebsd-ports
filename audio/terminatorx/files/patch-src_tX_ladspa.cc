--- src/tX_ladspa.cc.orig	Tue Aug 19 02:36:40 2003
+++ src/tX_ladspa.cc	Sat Aug 23 04:37:18 2003
@@ -44,8 +44,8 @@
 	ladspa_path_ptr=getenv("LADSPA_PATH");
 	
 	if (!ladspa_path_ptr)  {
-		tX_warning("LADSPA_PATH not set. Trying /usr/lib/ladspa:/usr/local/lib/ladspa");
-		strcpy(ladspa_path, "/usr/lib/ladspa:/usr/local/lib/ladspa");
+		tX_warning("LADSPA_PATH not set. Trying %%LOCALBASE%%/lib/ladspa");
+		strcpy(ladspa_path, "%%LOCALBASE%%/lib/ladspa");
 	}
 	else strcpy(ladspa_path, ladspa_path_ptr);
 	
