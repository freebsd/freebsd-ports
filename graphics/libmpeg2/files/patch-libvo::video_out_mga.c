--- libvo/video_out_mga.c.orig	Thu May  2 22:30:47 2002
+++ libvo/video_out_mga.c	Thu May  2 22:31:13 2002
@@ -44,6 +44,7 @@
 #include "attributes.h"
 #include "mmx.h"
 
+#if 0
 static void yuvinterleave (uint8_t * dst, uint8_t * pu, uint8_t * pv,
 			   int width)
 {
@@ -85,6 +86,7 @@
 	dst += bes_stride;
     } while (--i);
 }
+#endif
 
 static void yuv2g400_c (uint8_t * dst, uint8_t * py,
 			uint8_t * pu, uint8_t * pv,
