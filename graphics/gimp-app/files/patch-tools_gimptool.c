--- tools/gimptool.c.orig	2021-09-14 15:53:10 UTC
+++ tools/gimptool.c
@@ -748,9 +748,7 @@ get_sys_plugin_dir (gboolean forward_slashes)
   g_free (rprefix);
 #else
   dir = g_build_path (forward_slashes ? "/" : G_DIR_SEPARATOR_S,
-                      LIBDIR,
-                      "gimp",
-                      GIMP_PLUGIN_VERSION,
+                      GIMPPLUGINDIR,
                       "plug-ins",
                       NULL);
 #endif
