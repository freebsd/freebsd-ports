--- libmp3lame/lame.c.orig	2008-08-05 19:26:02.000000000 +0200
+++ libmp3lame/lame.c	2009-08-17 21:25:17.749630168 +0200
@@ -1602,6 +1602,13 @@
         /* update mfbuf[] counters */
         gfc->mf_size += n_out;
         assert(gfc->mf_size <= MFSIZE);
+
+        /* lame_encode_flush may have set gfc->mf_sample_to_encode to 0
+         * so we have to reinitialize it here when that happened.
+         */
+        if (gfc->mf_samples_to_encode < 1) {
+            gfc->mf_samples_to_encode = ENCDELAY + POSTDELAY;
+        }
         gfc->mf_samples_to_encode += n_out;
 
 
@@ -1931,6 +1938,10 @@
     int     frames_left;
     int     samples_to_encode = gfc->mf_samples_to_encode;
 
+    /* Was flush already called? */
+    if (gfc->mf_samples_to_encode < 1) {
+        return 0;
+    }
     memset(buffer, 0, sizeof(buffer));
     mp3count = 0;
     
@@ -1942,7 +1953,9 @@
     end_padding += pad_out_samples;
 
     frames_left = (samples_to_encode + pad_out_samples) / gfp->framesize;
-    while (frames_left > 0) {
+
+    /* send in a frame of 0 padding until all internal sample buffers are flushed */
+    while (frames_left > 0 && imp3 >= 0) {
         int frame_num = gfp->frameNum;
 
         mp3buffer_size_remaining = mp3buffer_size - mp3count;
@@ -1951,22 +1964,22 @@
         if (mp3buffer_size == 0)
             mp3buffer_size_remaining = 0;
 
-        /* send in a frame of 0 padding until all internal sample buffers
-         * are flushed
-         */
         imp3 = lame_encode_buffer(gfp, buffer[0], buffer[1], 32,
                                   mp3buffer, mp3buffer_size_remaining);
-        
-        if (frame_num != gfp->frameNum) {
-            --frames_left;
-        }
-        if (imp3 < 0) {
-            /* some type of fatal error */
-            return imp3;
-        }
         mp3buffer += imp3;
         mp3count += imp3;
+	frames_left -= (frame_num != gfp->frameNum) ? 1 : 0;
     }
+    /* Set gfc->mf_samples_to_encode to 0, so we may detect
+     * and break loops calling it more than once in a row.
+     */
+    gfc->mf_samples_to_encode = 0;
+
+    if (imp3 < 0) {
+        /* some type of fatal error */
+        return imp3;
+    }
+
     mp3buffer_size_remaining = mp3buffer_size - mp3count;
     /* if user specifed buffer size = 0, dont check size */
     if (mp3buffer_size == 0)
