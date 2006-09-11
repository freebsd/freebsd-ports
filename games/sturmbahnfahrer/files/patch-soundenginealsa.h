--- soundenginealsa.h.orig	Mon Sep  4 19:47:37 2006
+++ soundenginealsa.h	Wed Sep  6 04:38:00 2006
@@ -2,7 +2,6 @@
 #ifndef SOUNDENGINE_ALSA_H
 #define SOUNDENGINE_ALSA_H
 
-#include <alsa/asoundlib.h>
 
 class SoundClip;
 class SoundFeed;
@@ -29,8 +28,6 @@
     SoundFeedModulated *modulatedfeed;
     SoundFeedEngine    *enginefeed;
     SoundFeed          *activefeed;
-    snd_pcm_t *handle;
-    snd_pcm_uframes_t periodsz; // in frames
     int batchsize; // in periods
     int framelag; // in frames
     float lpfilter;
