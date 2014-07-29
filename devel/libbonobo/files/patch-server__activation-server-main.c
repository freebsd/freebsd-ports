--- activation-server/activation-server-main.c.orig	Fri Apr 15 20:37:07 2005
+++ activation-server/activation-server-main.c	Fri Aug 19 16:27:59 2005
@@ -197,7 +197,7 @@ build_src_dir (void)
                         g_string_append (gnome_od_source_dir,
                                          gnome_dirs[i]);
                         g_string_append (gnome_od_source_dir,
-                                         "/lib/bonobo/servers" G_SEARCHPATH_SEPARATOR_S);
+                                         "/libdata/bonobo/servers" G_SEARCHPATH_SEPARATOR_S);
                 }
                 g_strfreev (gnome_dirs);
                 g_string_append (real_od_source_dir,
