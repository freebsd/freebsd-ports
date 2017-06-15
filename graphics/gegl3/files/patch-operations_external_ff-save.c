https://git.gnome.org/browse/gegl/commit/?id=e26d6deace35

--- operations/external/ff-save.c.orig	2015-11-23 06:16:26 UTC
+++ operations/external/ff-save.c
@@ -696,10 +696,33 @@ write_video_frame (GeglProperties *o,
   else
     {
       /* encode the image */
-      out_size =
-        avcodec_encode_video (c,
-                              p->video_outbuf,
-                              p->video_outbuf_size, picture_ptr);
+      AVPacket pkt2;
+      int got_packet = 0;
+      av_init_packet(&pkt2);
+      pkt2.data = p->video_outbuf;
+      pkt2.size = p->video_outbuf_size;
+
+      out_size = avcodec_encode_video2(c, &pkt2, picture_ptr, &got_packet);
+    
+      if (!out_size && got_packet && c->coded_frame)
+        {
+          c->coded_frame->pts       = pkt2.pts;
+          c->coded_frame->key_frame = !!(pkt2.flags & AV_PKT_FLAG_KEY);
+          if (c->codec->capabilities & AV_CODEC_CAP_INTRA_ONLY)
+              c->coded_frame->pict_type = AV_PICTURE_TYPE_I;
+        }
+
+      if (pkt2.side_data_elems > 0)
+        {
+          int i;
+          for (i = 0; i < pkt2.side_data_elems; i++)
+            av_free(pkt2.side_data[i].data);
+          av_freep(&pkt2.side_data);
+          pkt2.side_data_elems = 0;
+        }
+
+      if (!out_size)
+        out_size = pkt2.size;
 
       /* if zero size, it means the image was buffered */
       if (out_size != 0)
