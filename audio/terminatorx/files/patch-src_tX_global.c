--- src/tX_global.c.orig	Thu Aug 21 06:41:24 2003
+++ src/tX_global.c	Sat Aug 23 04:34:16 2003
@@ -127,7 +127,7 @@
 #endif		
 	globals.use_stdout_cmdline=0;
 	strcpy(globals.current_path, "");
-	strcpy(globals.lrdf_path, "/usr/share/ladspa/rdf:/usr/local/share/ladspa/rdf");
+	strcpy(globals.lrdf_path, "%%LOCALBASE%%/share/ladspa/rdf");
 	globals.fullscreen_enabled=0;
 	globals.confirm_events=0;
 	globals.compress_set_files=0;
