--- src/sound.h.orig	2003-04-03 13:27:29 UTC
+++ src/sound.h
@@ -22,9 +22,9 @@
 
 #include "global.h"
 
-Uint32 sample_rate;
-Uint8  bit_per_sample;
-Uint16 sample_per_update;
+extern Uint32 sample_rate;
+extern Uint8  bit_per_sample;
+extern Uint16 sample_per_update;
 
 typedef struct SoundM1
 {
@@ -61,7 +61,7 @@ typedef struct SoundM1
   float sample_env_per_step;
   float cp;
 }SoundM1;
-SoundM1 snd_m1;
+extern SoundM1 snd_m1;
 
 typedef struct SoundM2
 {
@@ -92,7 +92,7 @@ typedef struct SoundM2
   float sample_env_per_step;
   float cp;
 }SoundM2;
-SoundM2 snd_m2;
+extern SoundM2 snd_m2;
 
 typedef struct SoundM3
 {
@@ -120,7 +120,7 @@ typedef struct SoundM3
   Uint16 sample_len; // durée en samples
   float cp;
 }SoundM3;
-SoundM3 snd_m3;
+extern SoundM3 snd_m3;
 
 typedef struct SoundM4
 {
@@ -149,7 +149,7 @@ typedef struct SoundM4
   float env_per_step;
   float sample_env_per_step;
 }SoundM4;
-SoundM4 snd_m4;
+extern SoundM4 snd_m4;
 
 /* Control general */
 typedef struct SoundG
@@ -177,7 +177,7 @@ typedef struct SoundG
   Uint8 Sound3_On_Off   ;
   Uint8 Sound4_On_Off   ;
 }SoundG;
-SoundG snd_g;
+extern SoundG snd_g;
 
 
 #define LEFT  1
