--- src/menus.c.orig	2002-01-14 22:13:59 UTC
+++ src/menus.c
@@ -219,7 +219,8 @@ a_menu_entry editor_entries[] = {
   { N_("NEW LEVEL"),	editor_menu },
   /* TRANS: Load an existing level for edition.  */
   { N_("LOAD LEVEL"),	editor_selector },
-  { N_("GO BACK"),	0 }
+  { N_("GO BACK"),	0 },
+  { 0,			0 }
 };
 
 a_menu *editor_menu_data;
