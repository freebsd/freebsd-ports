--- ffmpeg_frame.c.orig	2010-07-21 10:31:08.581341617 +0200
+++ ffmpeg_frame.c	2010-07-21 10:31:21.405528178 +0200
@@ -333,7 +333,7 @@
 
     GET_FRAME_RESOURCE(getThis(), ff_frame);
 
-    _php_convert_frame(ff_frame, PIX_FMT_RGBA32);
+    _php_convert_frame(ff_frame, PIX_FMT_RGB32);
 
     return_value->value.lval = _php_get_gd_image(ff_frame->width, 
             ff_frame->height);
@@ -418,7 +418,7 @@
 
             /* create a an av_frame and allocate space for it */
             frame = avcodec_alloc_frame();
-            avpicture_alloc((AVPicture*)frame, PIX_FMT_RGBA32, width, height);
+            avpicture_alloc((AVPicture*)frame, PIX_FMT_RGB32, width, height);
 
             /* copy the gd image to the av_frame */
             _php_gd_image_to_avframe(gd_img, frame, width, height);
@@ -429,7 +429,7 @@
             /* set the ffpmeg_frame's properties */
             ff_frame->width = width;
             ff_frame->height = height;
-            ff_frame->pixel_format = PIX_FMT_RGBA32;
+            ff_frame->pixel_format = PIX_FMT_RGB32;
             break;
         default:
             zend_error(E_ERROR, "Invalid argument\n");
