--- src/misc_track.c.orig	Tue Oct 18 22:38:54 2005
+++ src/misc_track.c	Tue Oct 18 22:39:25 2005
@@ -544,9 +544,10 @@
    illegal, "0" is returned. */
 guint32 track_get_timestamp (Track *track, T_item t_item)
 {
+    guint32 *ptr;
     g_return_val_if_fail (track, 0);
 
-    guint32 *ptr = track_get_timestamp_ptr (track, t_item);
+    ptr = track_get_timestamp_ptr (track, t_item);
     if (ptr)  return *ptr;
     else      return 0;
 }
