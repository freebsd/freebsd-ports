--- libmp3lame/vorbis_interface.c.orig	Mon Mar 19 21:04:53 2001
+++ libmp3lame/vorbis_interface.c	Sat Sep 29 16:40:07 2001
@@ -29,6 +29,9 @@
 #include <limits.h>
 #include <time.h>
 #include "vorbis/codec.h"
+#include "vorbis/vorbisenc.h"
+#include "codec_internal.h"
+#include "registry.h"
 #include "modes/modes.h"
 #include "lame.h"
 #include "util.h"
@@ -210,7 +213,7 @@
 {
   lame_internal_flags *gfc = gfp->internal_flags;
   int samples,result,i,j,eof=0,eos=0,bout=0;
-  double **pcm;
+  sample_t **pcm;
 
   while(1){
 
@@ -350,31 +353,67 @@
 int lame_encode_ogg_init(lame_global_flags *gfp)
 {
   lame_internal_flags *gfc=gfp->internal_flags;
+#ifdef THIS_CODE_IS_NOT_BROKEN_ANYMORE     
   char comment[MAX_COMMENT_LENGTH+1];
+#endif
 
   
   /********** Encode setup ************/
   
   /* choose an encoding mode */
   /* (mode 0: 44kHz stereo uncoupled, roughly 128kbps VBR) */
-  if (gfp->compression_ratio < 5.01) {
-    memcpy(&vi2,&info_E,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_E \n" );
-  } else if (gfp->compression_ratio < 6) {
-    memcpy(&vi2,&info_D,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_D \n" );
-  } else if (gfp->compression_ratio < 8) {
-    memcpy(&vi2,&info_C,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_C \n" );
-  } else if (gfp->compression_ratio < 10) {
-    memcpy(&vi2,&info_B,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_B \n" );
-  } else if (gfp->compression_ratio < 12) {
-    memcpy(&vi2,&info_A,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_A \n" );
-  } else {
-    memcpy(&vi2,&info_A,sizeof(vi2));
-    MSGF( gfc, "Encoding with Vorbis mode info_A \n" );
+  switch (gfc->channels_out) {
+  case 2:
+    if (gfp->compression_ratio < 5.01) {
+      memcpy(&vi2,&info_44c_E,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_E \n" );
+    } else if (gfp->compression_ratio < 6) {
+      memcpy(&vi2,&info_44c_D,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_D \n" );
+    } else if (gfp->compression_ratio < 8) {
+      memcpy(&vi2,&info_44c_C,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_C \n" );
+    } else if (gfp->compression_ratio < 10) {
+      memcpy(&vi2,&info_44c_B,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_B \n" );
+    } else if (gfp->compression_ratio < 12) {
+      memcpy(&vi2,&info_44c_A,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_A \n" );
+    } else if (gfp->compression_ratio < 14) {
+      memcpy(&vi2,&info_44c_X,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_X \n" );
+    } else if (gfp->compression_ratio < 16) {
+      memcpy(&vi2,&info_44c_Y,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_Y \n" );
+    } else if (gfp->compression_ratio < 18) {
+      memcpy(&vi2,&info_44c_Z,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_Z \n" );
+    } else {
+      memcpy(&vi2,&info_44c_A,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44c_A \n" );
+    }
+    break;
+
+  default:
+    if (gfp->compression_ratio < 10) {
+      memcpy(&vi2,&info_44_B,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_B \n" );
+    } else if (gfp->compression_ratio < 12) {
+      memcpy(&vi2,&info_44_A,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_A \n" );
+    } else if (gfp->compression_ratio < 14) {
+      memcpy(&vi2,&info_44_X,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_X \n" );
+    } else if (gfp->compression_ratio < 16) {
+      memcpy(&vi2,&info_44_Y,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_Y \n" );
+    } else if (gfp->compression_ratio < 18) {
+      memcpy(&vi2,&info_44_Z,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_Z \n" );
+    } else {
+      memcpy(&vi2,&info_44_A,sizeof(vi2));
+      MSGF( gfc, "Encoding with Vorbis mode info_44_A \n" );
+    }
   }
 
   vi2.channels = gfc->channels_out;
@@ -518,7 +557,7 @@
     int  bytes = 0;
   
     /* expose the buffer to submit data */
-    double **buffer = vorbis_analysis_buffer(&vd2,gfp->framesize);
+    float **buffer = vorbis_analysis_buffer(&vd2,gfp->framesize);
   
     /* change level of input by -90 dB (no de-interleaving!) */
     for ( i = 0; i < gfp->framesize; i++ )
