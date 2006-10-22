--- app/plug-in/plug-ins.c.orig	Wed Nov 17 15:51:50 2004
+++ app/plug-in/plug-ins.c	Sun Oct 22 18:58:36 2006
@@ -317,6 +317,8 @@
 
   if (! gimp->no_interface)
     {
+      gimp_menus_init (gimp, gimp->plug_in_defs, STD_PLUGINS_DOMAIN);
+
       gimp->load_procs = g_slist_sort_with_data (gimp->load_procs,
                                                  plug_ins_file_proc_compare,
                                                  gimp);
@@ -324,7 +326,6 @@
                                                  plug_ins_file_proc_compare,
                                                  gimp);
 
-      gimp_menus_init (gimp, gimp->plug_in_defs, STD_PLUGINS_DOMAIN);
     }
 
   /* build list of automatically started extensions */
