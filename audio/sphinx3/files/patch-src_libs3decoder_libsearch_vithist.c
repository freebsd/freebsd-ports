--- src/libs3decoder/libsearch/vithist.c.orig	2012-12-14 12:01:13.000000000 -0500
+++ src/libs3decoder/libsearch/vithist.c	2012-12-14 12:00:44.000000000 -0500
@@ -647,7 +647,7 @@ vithist_prune(vithist_t * vh, dict_t * d
 {
     int32 se, fe, filler_done, th;
     vithist_entry_t *ve;
-    heap_t h;
+    heap_t* h;
     s3wid_t *wid;
     int32 i;
 
