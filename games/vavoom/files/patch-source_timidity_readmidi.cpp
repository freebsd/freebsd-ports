--- source/timidity/readmidi.cpp.orig	2017-06-04 15:57:26.317968000 +0200
+++ source/timidity/readmidi.cpp	2017-06-04 16:07:48.260735000 +0200
@@ -569,7 +569,7 @@
 	int32 len, divisions;
 	int16 format, tracks, divisions_tmp;
 	int i;
-	char tmp[4];
+	char tmp[12];
 
 	song->midi_image = (uint8*)mimage;
 	song->image_left = msize;
