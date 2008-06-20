--- mbo.c.orig	2003-08-28 01:34:12.000000000 +0200
+++ mbo.c	2008-06-20 22:20:40.000000000 +0200
@@ -46,6 +46,17 @@
   return FALSE;
 }
 
+char *mbo_artistname (void) {
+  char *res = (char *)malloc(255);
+  if (mbo_ok == FALSE) return "";
+  memset(res, '\0', 255);
+  mb_GetResultData(mbo, MBE_AlbumGetAlbumArtistName, res, 255);
+  #ifdef DEBUG
+    fprintf (stderr, "cd_get_artistname: %s\n", res);
+  #endif
+  return res;
+}
+
 /* convenience hack. 0 is disc name, others are track names. */
 /* guess what, this too is XXX UNSAFE */
 char *mbo_trackname (int i) {
