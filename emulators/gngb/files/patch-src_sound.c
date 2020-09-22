--- src/sound.c.orig	2003-04-03 13:27:29 UTC
+++ src/sound.c
@@ -53,10 +53,17 @@ Uint16 wduty[4][8] = 
   {0,0,0,-1,-1,-1,-1,-1 }
 };
 
+SoundM1 snd_m1;
+SoundM2 snd_m2;
+SoundM3 snd_m3;
+SoundM4 snd_m4;
+SoundG snd_g;
 
 double freq_table[2048];
 double freq_table_m3[2048];
 long double freq_table_m4[256];
+Uint32 sample_rate;
+Uint16 sample_per_update;
 
 float lastpos=0,curpos=0;
 Uint32 buf_size;
