--- src/output/alsa-playback/xconvert.c.orig	2012-12-02 14:30:50.000000000 +0100
+++ src/output/alsa-playback/xconvert.c	2012-12-02 14:33:58.000000000 +0100
@@ -57,6 +57,7 @@
 
 #endif
 
+#define uint size_t
 
 struct buffer {
     void *buffer;
