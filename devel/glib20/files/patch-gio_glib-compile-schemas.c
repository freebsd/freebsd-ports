--- gio/glib-compile-schemas.c.orig	2017-08-07 16:58:31.000000000 +0200
+++ gio/glib-compile-schemas.c	2017-09-15 09:25:19.746310000 +0200
@@ -1219,6 +1219,7 @@ parse_state_start_schema (ParseState  *state,
       return;
     }
 
+#if 0
   if (path && (g_str_has_prefix (path, "/apps/") ||
                g_str_has_prefix (path, "/desktop/") ||
                g_str_has_prefix (path, "/system/")))
@@ -1231,6 +1232,7 @@ parse_state_start_schema (ParseState  *state,
       g_printerr ("%s\n", message);
       g_free (message);
     }
+#endif
 
   state->schema_state = schema_state_new (path, gettext_domain,
                                           extends, extends_name, list_of);
