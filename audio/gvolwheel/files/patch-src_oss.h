--- src/oss.h.orig	2020-08-01 09:32:59 UTC
+++ src/oss.h
@@ -23,7 +23,7 @@ struct stereo_volume
 	unsigned char right;
 };
 
-struct stereo_volume vol;
+extern struct stereo_volume vol;
 
 int vol_backend_init(char *device);
 void vol_backend_set(int mixer, int value);
