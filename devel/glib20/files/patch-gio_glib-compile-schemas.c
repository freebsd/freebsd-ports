--- gio/glib-compile-schemas.c.orig	2012-06-14 16:39:22.000000000 +0200
+++ gio/glib-compile-schemas.c	2012-06-14 16:39:55.000000000 +0200
@@ -1204,11 +1204,13 @@
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
     g_printerr ("warning: Schema '%s' has path '%s'.  Paths starting with "
                 "'/apps/', '/desktop/' or '/system/' are deprecated.\n", id, path);
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);
