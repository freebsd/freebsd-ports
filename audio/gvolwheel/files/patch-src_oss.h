--- src/oss.h.orig	2020-08-29 07:49:49 UTC
+++ src/oss.h
@@ -23,8 +23,8 @@ struct stereo_volume
 	unsigned char right;
 };
 
-struct stereo_volume vol;
+extern struct stereo_volume oss_vol;
 
 int vol_backend_init(char *device);
 void vol_backend_set(int mixer, int value);
-int vol_backend_get(int mixer);
\ No newline at end of file
+int vol_backend_get(int mixer);
