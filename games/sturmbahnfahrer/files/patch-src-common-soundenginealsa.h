--- src-common/soundenginealsa.h.orig	Thu May 17 20:02:03 2007
+++ src-common/soundenginealsa.h	Thu Aug  9 02:17:07 2007
@@ -2,8 +2,6 @@
 #ifndef SOUNDENGINE_ALSA_H
 #define SOUNDENGINE_ALSA_H
 
-#include <alsa/asoundlib.h>
-
 class SoundClip;
 class SoundFeed;
 class SoundFeedSimple;
@@ -29,8 +27,6 @@
     SoundFeedModulated *modulatedfeed;
     SoundFeedEngine    *enginefeed;
     SoundFeed          *activefeed;
-    snd_pcm_t *handle;
-    snd_pcm_uframes_t periodsz; // in frames
     int batchsize; // in periods
     int framelag; // in frames
     float lpfilter;
