
$FreeBSD$

--- src/anjuta.c	2002/01/04 13:31:53	1.1
+++ src/anjuta.c	2002/01/04 13:34:07
@@ -148,7 +148,7 @@
 		app->fileselection = create_fileselection_gui (&fsd1);
 		
 		/* Set to the current dir */
-		fileselection_set_dir (app->fileselection, (gchar *)get_current_dir_name());
+		fileselection_set_dir (app->fileselection, (gchar *)g_get_current_dir ());
 		
 		app->save_as_fileselection = create_fileselection_gui (&fsd2);
 		app->save_as_build_msg_sel = create_fileselection_gui (&fsd3);
