--- sfi/glib-extra.h.orig	Sun May  7 16:28:20 2006
+++ sfi/glib-extra.h	Sun May  7 16:28:31 2006
@@ -90,8 +90,6 @@
 gchar*		g_strdup_rstrip   (const gchar	 *string);
 gchar*		g_strdup_lstrip   (const gchar	 *string);
 
-const gchar*    g_intern_string         (const gchar   *string);
-const gchar*    g_intern_static_string  (const gchar   *string);
 const gchar*    g_intern_strconcat      (const gchar   *first_string,
                                          ...);
 const gchar*    g_intern_printf         (const gchar   *format,
