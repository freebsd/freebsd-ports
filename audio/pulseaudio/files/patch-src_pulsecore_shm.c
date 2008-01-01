--- src/pulsecore/shm.c.orig	2007-10-28 15:13:53.000000000 -0400
+++ src/pulsecore/shm.c	2008-01-01 16:19:19.000000000 -0500
@@ -80,7 +80,7 @@ struct shm_marker {
 };
 
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    pa_snprintf(fn, l, "/pulse-shm-%u", id);
+    pa_snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
 
