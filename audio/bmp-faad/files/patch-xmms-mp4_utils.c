--- plugins/xmms/src/mp4_utils.c.orig	Thu Dec  4 03:37:56 2003
+++ plugins/xmms/src/mp4_utils.c	Sun Sep 18 00:00:40 2005
@@ -54,7 +54,7 @@
     const char *trackType = MP4GetTrackType(file, trackID);
     if(!strcmp(trackType, MP4_AUDIO_TRACK_TYPE)){//we found audio track !
       int j=0;
-      u_int8_t audiotype = MP4GetTrackAudioType(file, trackID);
+      u_int8_t audiotype = MP4GetTrackEsdsObjectTypeId(file, trackID);
       while(mp4AudioTypes[j]){ // what kind of audio is ?
 	if(mp4AudioTypes[j] == audiotype){
 	  if(mp4AudioTypes[j] == MP4_MPEG4_AUDIO_TYPE){//MPEG4 audio ok
@@ -126,7 +126,7 @@
     printf("Track %d, %s", trackID, trackType);
     if(!strcmp(trackType, MP4_AUDIO_TRACK_TYPE)){//we found audio track !
       int j=0;
-      u_int8_t audiotype = MP4GetTrackAudioType(mp4file, trackID);
+      u_int8_t audiotype = MP4GetTrackEsdsObjectTypeId(mp4file, trackID);
       while(mp4AudioTypes[j]){ // what kind of audio is ?
 	if(mp4AudioTypes[j] == audiotype){
 	  if(mp4AudioTypes[j] == MP4_MPEG4_AUDIO_TYPE){
