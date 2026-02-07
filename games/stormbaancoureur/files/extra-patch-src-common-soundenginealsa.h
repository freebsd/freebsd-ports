--- src-common/soundenginealsa.h.orig	2008-04-20 16:00:03 UTC
+++ src-common/soundenginealsa.h
@@ -4,8 +4,6 @@
 
 #include <string>
 
-#include <alsa/asoundlib.h>
-
 class SoundClip;
 class SoundFeed;
 class SoundFeedSimple;
@@ -31,9 +29,6 @@ class SoundEngineAlsa
     SoundFeedModulated *modulatedfeed;
     SoundFeedEngine    *enginefeed;
     SoundFeed          *activefeed;
-    snd_pcm_t *handle;
-    snd_pcm_uframes_t periodsz; // in frames
-    snd_pcm_uframes_t buffersz; // in frames
     int batchsize; // in periods
     int framelag; // in frames
     float lpfilter;
