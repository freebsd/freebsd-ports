--- panel-plugin/xkb.c.orig	Wed Jun 30 11:46:49 2004
+++ panel-plugin/xkb.c	Sun Feb  6 12:51:04 2005
@@ -264,12 +264,12 @@
   char *group;
   
   group = strdup(get_symbol_name_by_res_no(current_group_xkb_no));
+  to_lower(group);
   strcpy(filename, FLAGSDIR);
   strcat(filename, "/");
   strcat(filename, group);
   strcat(filename, ".png");
-  to_lower(filename);
   
   free(group);
   
