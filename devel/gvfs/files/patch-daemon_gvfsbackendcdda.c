--- daemon/gvfsbackendcdda.c.orig	2012-05-15 18:01:50 +0000
+++ daemon/gvfsbackendcdda.c
@@ -55,7 +55,12 @@
 #include "gvfsjobenumerate.h"
 
 #define DO_NOT_WANT_PARANOIA_COMPATIBILITY
-#include <cdio/paranoia.h>
+#define HAVE_PARANOIA_NEW_INCLUDES
+#ifdef HAVE_PARANOIA_NEW_INCLUDES
+  #include <cdio/paranoia/paranoia.h>
+#else
+  #include <cdio/paranoia.h>
+#endif
 #include <cdio/cdio.h>
 
 /* TODO:
@@ -158,6 +163,16 @@ release_metadata (GVfsBackendCdda *cdda_
   cdda_backend->tracks = NULL;
 }
 
+static char *
+cdtext_string_to_utf8 (const char *string)
+{
+  if (string == NULL)
+    return NULL;
+
+  /* CD-text doesn't specify encoding. In case outside ascii, assume latin-1. */
+  return g_convert (string, -1, "UTF-8", "ISO-8859-1", NULL, NULL, NULL);
+}
+
 static void
 fetch_metadata (GVfsBackendCdda *cdda_backend)
 {
@@ -169,11 +184,22 @@ fetch_metadata (GVfsBackendCdda *cdda_ba
   if (!cdio)
     return;
 
-  cdtext = cdio_get_cdtext(cdio, 0);
+#if LIBCDIO_VERSION_NUM >= 84
+  cdtext = cdio_get_cdtext (cdio);
+#else
+  cdtext = cdio_get_cdtext (cdio, 0);
+#endif /* LIBCDIO_VERSION_NUM >= 84 */
+
   if (cdtext) {
-    cdda_backend->album_title = g_strdup (cdtext_get (CDTEXT_TITLE, cdtext));
-    cdda_backend->album_artist = g_strdup (cdtext_get (CDTEXT_PERFORMER, cdtext));
-    cdda_backend->genre = g_strdup (cdtext_get (CDTEXT_GENRE, cdtext));
+#if LIBCDIO_VERSION_NUM >= 84
+    cdda_backend->album_title = cdtext_string_to_utf8 (cdtext_get_const (cdtext, CDTEXT_FIELD_TITLE, 0));
+    cdda_backend->album_artist = cdtext_string_to_utf8 (cdtext_get_const (cdtext, CDTEXT_FIELD_PERFORMER, 0));
+    cdda_backend->genre = cdtext_string_to_utf8 (cdtext_get_const (cdtext, CDTEXT_FIELD_GENRE, 0));
+#else
+    cdda_backend->album_title = cdtext_string_to_utf8 (cdtext_get_const (CDTEXT_TITLE, cdtext));
+    cdda_backend->album_artist = cdtext_string_to_utf8 (cdtext_get_const (CDTEXT_PERFORMER, cdtext));
+    cdda_backend->genre = cdtext_string_to_utf8 (cdtext_get_const (CDTEXT_GENRE, cdtext));
+#endif /* LIBCDIO_VERSION_NUM >= 84 */
   }
 
   cdtrack = cdio_get_first_track_num(cdio);
@@ -182,10 +208,17 @@ fetch_metadata (GVfsBackendCdda *cdda_ba
   for ( ; cdtrack < last_cdtrack; cdtrack++ ) {
     GVfsBackendCddaTrack *track;
     track = g_new0 (GVfsBackendCddaTrack, 1);
-    cdtext = cdio_get_cdtext(cdio, cdtrack);
+#if LIBCDIO_VERSION_NUM < 84
+    cdtext = cdio_get_cdtext (cdio, cdtrack);
+#endif /* LIBCDIO_VERSION_NUM < 84 */
     if (cdtext) {
-      track->title = g_strdup (cdtext_get (CDTEXT_TITLE, cdtext));
-      track->artist = g_strdup (cdtext_get (CDTEXT_PERFORMER, cdtext));
+#if LIBCDIO_VERSION_NUM >= 84
+      track->title = cdtext_string_to_utf8 (cdtext_get_const (cdtext, CDTEXT_FIELD_TITLE, cdtrack));
+      track->artist = cdtext_string_to_utf8 (cdtext_get_const (cdtext, CDTEXT_FIELD_PERFORMER, cdtrack));
+#else
+      track->title = cdtext_string_to_utf8 (cdtext_get_const (CDTEXT_TITLE, cdtext));
+      track->artist = cdtext_string_to_utf8 (cdtext_get_const (CDTEXT_PERFORMER, cdtext));
+#endif /* LIBCDIO_VERSION_NUM >= 84 */
     }
     track->duration = cdio_get_track_sec_count (cdio, cdtrack) / CDIO_CD_FRAMES_PER_SEC;
 
@@ -961,8 +994,10 @@ do_query_info (GVfsBackend *backend,
       g_file_info_set_display_name (info, _("Audio Disc")); /* TODO: fill in from metadata */
       g_file_info_set_file_type (info, G_FILE_TYPE_DIRECTORY);
       g_file_info_set_content_type (info, "inode/directory");
-      SET_INFO ("xattr::org.gnome.audio.title", cdda_backend->album_title);
-      SET_INFO ("xattr::org.gnome.audio.artist", cdda_backend->album_artist);
+      if (cdda_backend->album_title)
+        SET_INFO ("xattr::org.gnome.audio.title", cdda_backend->album_title);
+      if (cdda_backend->album_artist)
+        SET_INFO ("xattr::org.gnome.audio.artist", cdda_backend->album_artist);
       SET_INFO ("xattr::org.gnome.audio.genre", cdda_backend->genre);
       g_file_info_set_size (info, 0);
       icon = g_themed_icon_new ("folder");
