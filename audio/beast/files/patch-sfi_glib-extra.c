--- sfi/glib-extra.c.orig	Sun May  7 16:28:07 2006
+++ sfi/glib-extra.c	Sun May  7 16:28:15 2006
@@ -170,18 +170,6 @@
   return NULL;
 }
 
-const gchar*
-g_intern_string (const gchar *string)
-{
-  return string ? g_quark_to_string (g_quark_from_string (string)) : NULL;
-}
-
-const gchar*
-g_intern_static_string (const gchar   *string)
-{
-  return string ? g_quark_to_string (g_quark_from_static_string (string)) : NULL;
-}
-
 static gchar*
 delim_concat_varargs (const gchar *first_string,
                       gchar        delim,
