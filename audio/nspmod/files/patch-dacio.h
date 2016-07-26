--- dacio.h.orig	1995-09-16 07:01:08 UTC
+++ dacio.h
@@ -3,6 +3,7 @@
 #endif
 
 typedef struct {
+    int bits;
     int speed;
     int stereo;
 } DacioConfInfo;
