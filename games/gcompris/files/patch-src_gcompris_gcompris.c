--- src/gcompris/gcompris.c.orig	2010-02-13 08:38:20.000000000 -0500
+++ src/gcompris/gcompris.c	2010-03-21 14:22:42.000000000 -0400
@@ -1202,7 +1202,7 @@ static void load_properties ()
 #ifdef NSBUNDLE
   exec_prefix = gcompris_nsbundle_resource ();
 #else
-  exec_prefix = gbr_find_exe_dir(NULL);
+  exec_prefix = gbr_find_exe_dir("%%PREFIX%%");
 #endif
   g_warning("exec_prefix %s\n", (exec_prefix==NULL ? "NONE" : exec_prefix));
 
