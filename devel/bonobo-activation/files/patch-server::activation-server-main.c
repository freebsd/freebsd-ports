--- server/activation-server-main.c.orig	Tue Oct 29 05:51:19 2002
+++ server/activation-server-main.c	Fri Nov  8 03:21:04 2002
@@ -131,7 +131,7 @@
                         g_string_append (gnome_od_source_dir,
                                          gnome_dirs[i]);
                         g_string_append (gnome_od_source_dir,
-                                         "/lib/bonobo/servers:");
+                                         "/libdata/bonobo/servers:");
                 }
                 g_strfreev (gnome_dirs);
                 g_string_append_c (real_od_source_dir, ':');
