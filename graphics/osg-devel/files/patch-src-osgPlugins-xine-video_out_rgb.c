--- src/osgPlugins/xine/video_out_rgb.c.orig	2012-02-09 20:42:47.000000000 +0400
+++ src/osgPlugins/xine/video_out_rgb.c	2012-03-06 23:06:37.317706687 +0400
@@ -51,6 +51,11 @@
 #include "xine/video_out.h"
 #include "video_out_rgb.h"
 
+#if !(XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2))
+#define round round_not
+#include <libavutil/mem.h>
+#undef round
+#endif
 
 #define THIS  "video_out_rgb"
 
@@ -2237,9 +2242,15 @@
 
 	EVAL(vo_frame != NULL)
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	release(frame->chunk[0]);
 	release(frame->chunk[1]);
 	release(frame->chunk[2]);
+#else
+	av_freep(frame->chunk[0]);
+	av_freep(frame->chunk[1]);
+	av_freep(frame->chunk[2]);
+#endif
 	free(frame);
 
 FAILURE:
@@ -2303,9 +2314,15 @@
 	this->frame_width      = frame->width;
 	this->frame_height     = frame->height;
 
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	release(frame->chunk[0]);
 	release(frame->chunk[1]);
 	release(frame->chunk[2]);
+#else
+	av_freep(frame->chunk[0]);
+	av_freep(frame->chunk[1]);
+	av_freep(frame->chunk[2]);
+#endif
 
 CHECK_FRAME:
 	switch(frame->format)
@@ -2322,6 +2339,7 @@
 			frame->vo_frame.pitches[0] = (frame->width > 7) ? frame->width : 8;
 			frame->vo_frame.pitches[1] = (frame->width > 15) ? (frame->width >> 1) : 8;
 			frame->vo_frame.pitches[2] = frame->vo_frame.pitches[1];
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 			frame->vo_frame.base[0] = (uint8_t*) xine_xmalloc_aligned(16,
 							 	frame->vo_frame.pitches[0] * frame->height,
 							 	&(frame->chunk[0]));
@@ -2331,6 +2349,14 @@
 			frame->vo_frame.base[2] = (uint8_t*) xine_xmalloc_aligned(16,
 								frame->vo_frame.pitches[2] * (frame->height >> 1),
 								&(frame->chunk[2]));
+#else
+			frame->vo_frame.base[0] = (uint8_t*)(frame->chunk[0] =
+				av_mallocz(frame->vo_frame.pitches[0] * frame->height));
+			frame->vo_frame.base[1] = (uint8_t*)(frame->chunk[1] =
+				av_mallocz(frame->vo_frame.pitches[1] * (frame->height >> 1)));
+			frame->vo_frame.base[2] = (uint8_t*)(frame->chunk[2] =
+				av_mallocz(frame->vo_frame.pitches[2] * (frame->height >> 1)));
+#endif
 		}
 		break;
 
@@ -2346,9 +2372,14 @@
 			frame->vo_frame.pitches[0] = (frame->width > 3) ? (frame->width << 1) : 8;
 			frame->vo_frame.pitches[1] = 0;
 			frame->vo_frame.pitches[2] = 0;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 			frame->vo_frame.base[0] = (uint8_t*) xine_xmalloc_aligned(16,
 								frame->vo_frame.pitches[0] * frame->height,
 								&(frame->chunk[0]));
+#else
+			frame->vo_frame.base[0] = (uint8_t*)(frame->chunk[0] =
+				av_mallocz(frame->vo_frame.pitches[0] * frame->height));
+#endif
 			frame->vo_frame.base[1] = NULL;
 			frame->vo_frame.base[2] = NULL;
 		}
