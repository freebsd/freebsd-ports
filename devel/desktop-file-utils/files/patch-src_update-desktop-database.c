From f0a269e1d65843822915faa1bb020da8b6b9954c Mon Sep 17 00:00:00 2001
From: Vincent Untz <vuntz@gnome.org>
Date: Mon, 07 Jan 2013 08:02:08 +0000
Subject: update-desktop-database: List only once a desktop file per mime type

If a desktop file is registering the same mime type more than once
(useless but okay), the desktop file was listed more than once for that
mime type in mimeinfo.cache.

It's easy to avoid, so make sure we only have a desktop file once per
mime type.
---
diff --git a/src/update-desktop-database.c b/src/update-desktop-database.c
index ffc1440..7f48357 100644
--- src/update-desktop-database.c
+++ src/update-desktop-database.c
@@ -83,6 +83,13 @@ cache_desktop_file (const char  *desktop_file,
 
   desktop_files = (GList *) g_hash_table_lookup (mime_types_map, mime_type);
 
+  /* do not add twice a desktop file mentioning the mime type more than once
+   * (no need to use g_list_find() because we cache all mime types registered
+   * by a desktop file before moving to another desktop file) */
+  if (desktop_files &&
+      strcmp (desktop_file, (const char *) desktop_files->data) == 0)
+    return;
+
   desktop_files = g_list_prepend (desktop_files, g_strdup (desktop_file));
   g_hash_table_insert (mime_types_map, g_strdup (mime_type), desktop_files);
 }
--
cgit v0.9.0.2-2-gbebe
