--- plugins/xanim/lqt_codec.c.orig	Tue Jun 11 09:17:44 2002
+++ plugins/xanim/lqt_codec.c	Sat Aug 10 07:42:38 2002
@@ -10,17 +10,15 @@
                              int track)
   {
   int compressed_size, result, bpp, i, use_temp;
-  int video_width, video_height;
-
-  fprintf(stderr, "Decode video_1\n");
-  
-  quicktime_trak_t *trak = file->vtracks[track].track;
-  video_height = trak->tkhd.track_height;
-  video_width = trak->tkhd.track_width;
   
   quicktime_video_map_t *vtrack = &(file->vtracks[track]);
+  quicktime_trak_t *trak = file->vtracks[track].track;
+  int video_height = trak->tkhd.track_height;
+  int video_width = trak->tkhd.track_width;
   lqt_xanim_codec_1_t * codec = (lqt_xanim_codec_1_t*)(((quicktime_codec_t*)vtrack->codec)->priv);
   
+  fprintf(stderr, "Decode video_1\n");
+
   quicktime_set_video_position(file, vtrack->current_position, track);
   compressed_size =
     quicktime_frame_size(file, vtrack->current_position, track);
@@ -127,16 +125,15 @@
 
 void lqt_xanim_init_vcodec_1(quicktime_t * file, int track)
   {
-  int video_width, video_height, i;
-
-  init_xanimcodecs();
-  
-  quicktime_trak_t *trak = file->vtracks[track].track;
-  video_height = trak->tkhd.track_height;
-  video_width = trak->tkhd.track_width;
+  int i;
 
   quicktime_video_map_t *vtrack = &(file->vtracks[track]);
+  quicktime_trak_t *trak = file->vtracks[track].track;
+  int video_height = trak->tkhd.track_height;
+  int video_width = trak->tkhd.track_width;
   lqt_xanim_codec_1_t * codec = (lqt_xanim_codec_1_t*)(((quicktime_codec_t*)vtrack->codec)->priv);
+
+  init_xanimcodecs();
 
   codec->info.cmd = 0;                                         /* decode or query */
   codec->info.skip_flag = 0;                                   /* skip_flag */
