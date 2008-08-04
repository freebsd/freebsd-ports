--- src/gcompris/gcompris.c.orig	2008-08-04 14:21:07.000000000 -0400
+++ src/gcompris/gcompris.c	2008-08-04 14:21:23.000000000 -0400
@@ -1127,11 +1127,11 @@ static void load_properties ()
 #ifdef NSBUNDLE
   exec_prefix = gcompris_nsbundle_resource ();
 #else
-  exec_prefix = gbr_find_exe_dir("");
+  exec_prefix = gbr_find_exe_dir("%%PREFIX%%");
 #endif
   g_warning("exec_prefix %s\n", exec_prefix);
 
-  prefix_dir = gbr_find_prefix(NULL);
+  prefix_dir = gbr_find_prefix("%%PREFIX%%");
 
   /* Check if we are in the source code (developper usage) */
   tmpstr = g_strconcat(prefix_dir, "/gcompris/gcompris.c", NULL);
