--- src/output/alsa-playback/xconvert.c.orig	2007-02-01 12:59:50 UTC
+++ src/output/alsa-playback/xconvert.c
@@ -57,6 +57,7 @@
 
 #endif
 
+#define uint size_t
 
 struct buffer {
     void *buffer;
