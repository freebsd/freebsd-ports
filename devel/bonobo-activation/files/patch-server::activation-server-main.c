
$FreeBSD$

--- server/activation-server-main.c	2002/02/13 17:50:37	1.1
+++ server/activation-server-main.c	2002/02/13 17:51:02
@@ -196,7 +196,7 @@
                                 g_string_append (gnome_od_source_dir,
                                                  gnome_dirs[i]);
                                 g_string_append (gnome_od_source_dir,
-                                                 "/lib/bonobo/servers:");
+                                                 "/libdata/bonobo/servers:");
                         }
                         g_strfreev (gnome_dirs);
 			g_string_append_c (real_od_source_dir, ':');
