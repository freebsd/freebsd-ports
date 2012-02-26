--- src/osgPlugins/xine/video_out_rgb.c.orig
+++ src/osgPlugins/xine/video_out_rgb.c
@@ -51,6 +51,11 @@
 #include "xine/video_out.h"
 #include "video_out_rgb.h"
 
+#if !(XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2))
+#define round round_not
+#include <libavutil/mem.h>
+#undef round
+#endif
 
 #define THIS  "video_out_rgb"
 
@@ -2235,9 +2240,15 @@ rgbout_frame_dispose(vo_frame_t* vo_fram
 
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
@@ -2301,9 +2312,15 @@ rgbout_update_frame_format(vo_driver_t* 
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
@@ -2320,6 +2337,7 @@ CHECK_FRAME:
 			frame->vo_frame.pitches[0] = (frame->width > 7) ? frame->width : 8;
 			frame->vo_frame.pitches[1] = (frame->width > 15) ? (frame->width >> 1) : 8;
 			frame->vo_frame.pitches[2] = frame->vo_frame.pitches[1];
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 			frame->vo_frame.base[0] = (uint8_t*) xine_xmalloc_aligned(16,
 							 	frame->vo_frame.pitches[0] * frame->height,
 							 	&(frame->chunk[0]));
@@ -2329,6 +2347,14 @@ CHECK_FRAME:
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
 
@@ -2344,9 +2370,14 @@ CHECK_FRAME:
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
@@ -2767,8 +2798,13 @@ init_class(xine_t* xine, void* vo_visual
 	clear(rgb_class, sizeof(rgbout_class_t));
 
 	rgb_class->driver_class.open_plugin     = open_plugin;
+#if XINE_MAJOR_VERSION < 1 || (XINE_MAJOR_VERSION == 1 && XINE_MINOR_VERSION < 2)
 	rgb_class->driver_class.get_identifier  = get_identifier;
 	rgb_class->driver_class.get_description = get_description;
+#else
+	rgb_class->driver_class.identifier      = get_identifier(NULL);
+	rgb_class->driver_class.description     = get_description(NULL);
+#endif
 	rgb_class->driver_class.dispose         = dispose_class;
 
 	return(rgb_class);
