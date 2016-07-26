--- src/pulsecore/shm.c.orig	2015-12-31 06:28:35 UTC
+++ src/pulsecore/shm.c
@@ -95,7 +95,7 @@ struct shm_marker {
 
 #ifdef HAVE_SHM_OPEN
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    pa_snprintf(fn, l, "/pulse-shm-%u", id);
+    pa_snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
 #endif
