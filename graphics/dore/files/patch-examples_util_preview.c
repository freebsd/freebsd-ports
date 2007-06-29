--- examples/util/preview.c.orig	Fri Jan 13 04:13:44 1995
+++ examples/util/preview.c	Fri Jun 29 17:20:09 2007
@@ -64,6 +64,8 @@
 
 
 
+static DtObject MakeNewDefinitionGroup(), MakeNewDisplayGroup();
+static MakeNewView();
 
 void view_preview (
     DtObject user_view,
@@ -71,7 +73,6 @@
     DtInt save_list[])
 {
 	DtObject new_device, new_view, new_definition_group, new_display_group;
-	DtObject MakeNewDefinitionGroup(), MakeNewDisplayGroup();
 
 	MakeNewView(&new_device, &new_view);
 	new_definition_group = MakeNewDefinitionGroup();
