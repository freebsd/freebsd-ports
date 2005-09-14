--- plugins/xmms/src/mp4_utils.c.orig	Thu Dec  4 05:07:56 2003
+++ plugins/xmms/src/mp4_utils.c	Fri Jul 29 11:11:21 2005
@@ -6,23 +6,35 @@
 
 const char *mp4AudioNames[]=
   {
-    "MPEG-1 Audio Layers 1,2 or 3",
-    "MPEG-2 low biterate (MPEG-1 extension) - MP3",
-    "MPEG-2 AAC Main Profile",
-    "MPEG-2 AAC Low Complexity profile",
-    "MPEG-2 AAC SSR profile",
-    "MPEG-4 audio (MPEG-4 AAC)",
-    0
+    "MPEG-4 AAC Main profile",
+    "MPEG-4 AAC Low Complexity profile",
+    "MPEG-4 AAC SSR profile",
+    "MPEG-4 AAC Long Term Prediction profile",
+    "MPEG-4 AAC Scalable",
+    "MPEG-4 CELP",
+    "MPEG-4 HVXC",
+    "MPEG-4 Text to Speech",
+    "MPEG-4 Main Synthetic profile",
+    "MPEG-4 Wavetable Synthesis profile",
+    "MPEG-4 MIDI profile",
+    "MPEG-4 Algorithmic Synthesis and Audio FX profile",
+    NULL
   };
 
 const u_int8_t mp4AudioTypes[] =
   {
-    MP4_MPEG1_AUDIO_TYPE,		// 0x6B
-    MP4_MPEG2_AUDIO_TYPE,		// 0x69
-    MP4_MPEG2_AAC_MAIN_AUDIO_TYPE,	// 0x66
-    MP4_MPEG2_AAC_LC_AUDIO_TYPE,	// 0x67
-    MP4_MPEG2_AAC_SSR_AUDIO_TYPE,	// 0x68
-    MP4_MPEG4_AUDIO_TYPE,		// 0x40
+    MP4_MPEG4_AAC_MAIN_AUDIO_TYPE,
+    MP4_MPEG4_AAC_LC_AUDIO_TYPE,
+    MP4_MPEG4_AAC_SSR_AUDIO_TYPE,
+    MP4_MPEG4_AAC_LTP_AUDIO_TYPE,
+    MP4_MPEG4_AAC_SCALABLE_AUDIO_TYPE,
+    MP4_MPEG4_CELP_AUDIO_TYPE,
+    MP4_MPEG4_HVXC_AUDIO_TYPE,
+    MP4_MPEG4_TTSI_AUDIO_TYPE,
+    MP4_MPEG4_MAIN_SYNTHETIC_AUDIO_TYPE,
+    MP4_MPEG4_WAVETABLE_AUDIO_TYPE,
+    MP4_MPEG4_MIDI_AUDIO_TYPE,
+    MP4_MPEG4_ALGORITHMIC_FX_AUDIO_TYPE,
     0
   };
 
@@ -54,7 +66,7 @@
     const char *trackType = MP4GetTrackType(file, trackID);
     if(!strcmp(trackType, MP4_AUDIO_TRACK_TYPE)){//we found audio track !
       int j=0;
-      u_int8_t audiotype = MP4GetTrackAudioType(file, trackID);
+      u_int8_t audiotype = MP4GetTrackAudioMpeg4Type(file, trackID);
       while(mp4AudioTypes[j]){ // what kind of audio is ?
 	if(mp4AudioTypes[j] == audiotype){
 	  if(mp4AudioTypes[j] == MP4_MPEG4_AUDIO_TYPE){//MPEG4 audio ok
@@ -64,9 +76,9 @@
 	  }
 	  else{
 	    printf("%s\n", mp4AudioNames[j]);
-	    if (mp4AudioTypes[j]== MP4_MPEG2_AAC_LC_AUDIO_TYPE ||
-		mp4AudioTypes[j]== MP4_MPEG2_AAC_MAIN_AUDIO_TYPE ||
-		mp4AudioTypes[j]== MP4_MPEG2_AAC_SSR_AUDIO_TYPE)
+	    if (mp4AudioTypes[j]== MP4_MPEG4_AAC_MAIN_AUDIO_TYPE ||
+		mp4AudioTypes[j]== MP4_MPEG4_AAC_LC_AUDIO_TYPE ||
+		mp4AudioTypes[j]== MP4_MPEG4_AAC_SSR_AUDIO_TYPE)
 	      return(trackID);
 	    return(-1);
 	  }
@@ -126,10 +138,11 @@
     printf("Track %d, %s", trackID, trackType);
     if(!strcmp(trackType, MP4_AUDIO_TRACK_TYPE)){//we found audio track !
       int j=0;
-      u_int8_t audiotype = MP4GetTrackAudioType(mp4file, trackID);
+      u_int8_t audiotype = MP4GetTrackAudioMpeg4Type(mp4file, trackID);
       while(mp4AudioTypes[j]){ // what kind of audio is ?
 	if(mp4AudioTypes[j] == audiotype){
-	  if(mp4AudioTypes[j] == MP4_MPEG4_AUDIO_TYPE){
+	  if(mp4AudioTypes[j] == MP4_MPEG4_AUDIO_TYPE ||
+	     mp4AudioTypes[j] == MP4_MPEG4_AAC_LC_AUDIO_TYPE){
 	    audiotype = MP4GetTrackAudioMpeg4Type(mp4file, trackID);
 	    g_print(" %s", mpeg4AudioNames[audiotype]);
 	  }
