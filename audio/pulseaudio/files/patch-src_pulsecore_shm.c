--- src/pulsecore/shm.c.orig	2009-08-19 10:17:06.000000000 +0800
+++ src/pulsecore/shm.c	2009-11-11 21:25:03.000000000 +0800
@@ -91,7 +91,7 @@
 #define SHM_MARKER_SIZE PA_ALIGN(sizeof(struct shm_marker))
 
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    pa_snprintf(fn, l, "/pulse-shm-%u", id);
+    pa_snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
 
@@ -142,7 +142,7 @@
         pa_random(&m->id, sizeof(m->id));
         segment_name(fn, sizeof(fn), m->id);
 
-        if ((fd = shm_open(fn, O_RDWR|O_CREAT|O_EXCL, mode & 0444)) < 0) {
+        if ((fd = shm_open(fn, O_RDWR|O_CREAT|O_EXCL, mode & 0644)) < 0) {
             pa_log("shm_open() failed: %s", pa_cstrerror(errno));
             goto fail;
         }
