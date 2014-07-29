--- src/menus.c.orig	Mon Jan 14 17:13:59 2002
+++ src/menus.c	Mon Mar  1 16:25:56 2004
@@ -219,7 +219,8 @@
   { N_("NEW LEVEL"),	editor_menu },
   /* TRANS: Load an existing level for edition.  */
   { N_("LOAD LEVEL"),	editor_selector },
-  { N_("GO BACK"),	0 }
+  { N_("GO BACK"),	0 },
+  { 0,			0 }
 };
 
 a_menu *editor_menu_data;
