--- src/pulsecore/shm.c.orig	2016-06-21 10:58:21 UTC
+++ src/pulsecore/shm.c
@@ -102,7 +102,7 @@ static inline size_t shm_marker_size(pa_
 
 #ifdef HAVE_SHM_OPEN
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    pa_snprintf(fn, l, "/pulse-shm-%u", id);
+    pa_snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
 #endif
