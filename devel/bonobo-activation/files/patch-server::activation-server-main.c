
$FreeBSD$

--- server/activation-server-main.c.orig	Tue May 14 04:51:55 2002
+++ server/activation-server-main.c	Mon May 27 13:36:25 2002
@@ -127,7 +127,7 @@
                         g_string_append (gnome_od_source_dir,
                                          gnome_dirs[i]);
                         g_string_append (gnome_od_source_dir,
-                                         "/lib/bonobo/servers:");
+                                         "/libdata/bonobo/servers:");
                 }
                 g_strfreev (gnome_dirs);
                 g_string_append_c (real_od_source_dir, ':');
