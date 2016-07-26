--- src/tX_global.c.orig	2011-01-30 21:01:31 UTC
+++ src/tX_global.c
@@ -127,7 +127,7 @@ void set_global_defaults() {
 #endif		
 	globals.use_stdout_cmdline=0;
 	strcpy(globals.current_path, "");
-	strcpy(globals.lrdf_path, "/usr/share/ladspa/rdf:/usr/local/share/ladspa/rdf");
+	strcpy(globals.lrdf_path, "%%LOCALBASE%%/share/ladspa/rdf");
 	globals.fullscreen_enabled=0;
 	globals.confirm_events=0;
 	globals.compress_set_files=0;
