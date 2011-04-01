--- ./plugins/dumb/dumb-kode54/src/it/itrender.c.orig	2011-03-31 17:50:48.000000000 +0200
+++ ./plugins/dumb/dumb-kode54/src/it/itrender.c	2011-03-31 17:51:47.000000000 +0200
@@ -3558,10 +3558,6 @@
 	playing->sample_vibrato_time += playing->sample->vibrato_speed;
 }
 
-#ifndef __linux__
-static inline float log2(float x) {return (float)log(x)/(float)log(2.0f);}
-#endif
-
 static int delta_to_note(float delta, int base)
 {
 	float note;
