Index: src/mp4file.c
diff -u -p src/mp4file.c.orig src/mp4file.c
--- src/mp4file.c.orig	Sat Jan 17 18:37:49 2004
+++ src/mp4file.c	Fri May  7 15:20:24 2004
@@ -109,6 +109,10 @@
 
 #include "mp4.h"
 
+#ifndef UINT64_TO_DOUBLE
+#define UINT64_TO_DOUBLE(a) ((double)((int64_t)(a)))
+#endif
+
 Track *file_get_mp4_info (gchar *mp4FileName)
 {
     Track *track = NULL;
@@ -342,7 +346,7 @@ Track *file_get_mp4_info (gchar *name)
     return NULL;
 }
 
-gboolean file_write_mp4_info (gchar *filename, Track *track, T_item tag_id)
+gboolean file_write_mp4_info (gchar *filename, Track *track)
 {
     gtkpod_warning (_("m4a/m4p metadata update for '%s' failed: m4a/m4p not supported without the mp4v2 library. You must compile the gtkpod source together with the mp4v2 library.\n"), filename);
     return FALSE;
