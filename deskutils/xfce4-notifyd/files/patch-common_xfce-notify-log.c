--- common/xfce-notify-log.c.orig	2020-08-17 22:20:52 UTC
+++ common/xfce-notify-log.c
@@ -37,6 +37,38 @@
 
 #include "xfce-notify-log.h"
 
+// import g_date_time_format_iso8601
+// from: https://git.sailfishos.org/mirror/glib/commit/dbabd2b8a745bfed4890f2d6cbd7d7848bc4f034
+gchar *
+g_date_time_format_iso8601 (GDateTime *datetime)
+{
+  GString *outstr = NULL;
+  gchar *main_date = NULL;
+  gint64 offset;
+
+  /* Main date and time. */
+  main_date = g_date_time_format (datetime, "%Y-%m-%dT%H:%M:%S");
+  outstr = g_string_new (main_date);
+  g_free (main_date);
+
+  /* Timezone. Format it as `%:::z` unless the offset is zero, in which case
+   * we can simply use `Z`. */
+  offset = g_date_time_get_utc_offset (datetime);
+
+  if (offset == 0)
+    {
+      g_string_append_c (outstr, 'Z');
+    }
+  else
+    {
+      gchar *time_zone = g_date_time_format (datetime, "%:::z");
+      g_string_append (outstr, time_zone);
+      g_free (time_zone);
+    }
+
+  return g_string_free (outstr, FALSE);
+}
+
 GdkPixbuf *
 notify_pixbuf_from_image_data (GVariant *image_data)
 {
