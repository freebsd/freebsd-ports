--- src/pulsecore/shm.c.orig	2013-04-14 06:42:35.000000000 +0200
+++ src/pulsecore/shm.c	2013-06-24 17:25:58.000000000 +0200
@@ -97,7 +97,7 @@ struct shm_marker {
 
 #ifdef HAVE_SHM_OPEN
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    pa_snprintf(fn, l, "/pulse-shm-%u", id);
+    pa_snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
 #endif
