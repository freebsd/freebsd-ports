--- geanyctags/src/geanyctags.c.orig	2018-07-11 18:51:49 UTC
+++ geanyctags/src/geanyctags.c
@@ -241,7 +241,7 @@ on_generate_tags(GtkMenuItem *menuitem, gpointer user_
 #ifndef G_OS_WIN32
 		gchar *find_string = generate_find_string(prj);
 		cmd = g_strconcat(find_string,
-			" | ctags --totals --fields=fKsSt --extra=-fq --c-kinds=+p --sort=foldcase --excmd=number -L - -f '",
+			" | exctags --totals --fields=fKsSt --extra=-fq --c-kinds=+p --sort=foldcase --excmd=number -L - -f '",
 			tag_filename, "'", NULL);
 		g_free(find_string);
 #else
