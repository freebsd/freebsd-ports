--- src/pulsecore/shm.c.orig	Thu May 17 11:57:56 2007
+++ src/pulsecore/shm.c	Thu May 17 11:58:10 2007
@@ -50,7 +50,7 @@
 #define MAX_SHM_SIZE (1024*1024*20)
 
 static char *segment_name(char *fn, size_t l, unsigned id) {
-    snprintf(fn, l, "/pulse-shm-%u", id);
+    snprintf(fn, l, "/tmp/pulse-shm-%u", id);
     return fn;
 }
