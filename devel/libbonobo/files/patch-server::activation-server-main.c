--- activation-server/activation-server-main.c.orig	Fri Oct 18 06:15:12 2002
+++ activation-server/activation-server-main.c	Sat Nov  9 01:50:36 2002
@@ -127,7 +127,7 @@
                         g_string_append (gnome_od_source_dir,
                                          gnome_dirs[i]);
                         g_string_append (gnome_od_source_dir,
-                                         "/lib/bonobo/servers:");
+                                         "/libdata/bonobo/servers:");
                 }
                 g_strfreev (gnome_dirs);
                 g_string_append_c (real_od_source_dir, ':');
