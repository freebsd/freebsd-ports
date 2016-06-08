--- plugins/project-manager/dialogs.c.orig	2013-11-23 11:05:34.823263596 +0000
+++ plugins/project-manager/dialogs.c	2013-11-23 11:05:53.553262862 +0000
@@ -97,6 +97,9 @@
 	N_COLUMNS
 };
 
+void pm_project_resize_properties_dialog (PropertiesTable *table);
+
+
 /* Helper functions
  *---------------------------------------------------------------------------*/
 
