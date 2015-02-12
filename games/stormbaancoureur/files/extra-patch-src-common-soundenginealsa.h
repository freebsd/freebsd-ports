--- src-common/soundenginealsa.h.orig	2008-01-03 07:29:23.000000000 +0300
+++ src-common/soundenginealsa.h	2008-02-09 00:52:09.000000000 +0300
@@ -2,8 +2,6 @@
 #ifndef SOUNDENGINE_ALSA_H
 #define SOUNDENGINE_ALSA_H
 
-#include <alsa/asoundlib.h>
-
 class SoundClip;
 class SoundFeed;
 class SoundFeedSimple;
@@ -29,9 +27,6 @@
     SoundFeedModulated *modulatedfeed;
     SoundFeedEngine    *enginefeed;
     SoundFeed          *activefeed;
-    snd_pcm_t *handle;
-    snd_pcm_uframes_t periodsz; // in frames
-    snd_pcm_uframes_t buffersz; // in frames
     int batchsize; // in periods
     int framelag; // in frames
     float lpfilter;
