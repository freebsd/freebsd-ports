https://gitlab.gnome.org/GNOME/glib/-/issues/2820

--- glib/ghash.h.orig	2022-11-24 12:29:05 UTC
+++ glib/ghash.h
@@ -162,7 +162,7 @@ gboolean g_str_equal    (gconstpointer  v1,
                          gconstpointer  v2);
 
 /* Macro for optimization in the case it is not used as callback function */
-#define g_str_equal(v1, v2) (strcmp ((gconstpointer) (v1), (gconstpointer) (v2)) == 0)
+#define g_str_equal(v1, v2) (strcmp ((const char *) (v1), (const char *) (v2)) == 0)
 
 GLIB_AVAILABLE_IN_ALL
 guint    g_str_hash     (gconstpointer  v);
