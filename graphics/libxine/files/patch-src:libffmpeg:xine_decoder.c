--- src/libffmpeg/xine_decoder.c.orig	Fri Oct 19 21:17:15 2001
+++ src/libffmpeg/xine_decoder.c	Fri Oct 19 21:17:39 2001
@@ -38,8 +38,8 @@
 #include "buffer.h"
 #include "metronom.h"
 
-#include "libavcodec/avcodec.h"
-#include "libavcodec/dsputil.h"
+#include <libavcodec/avcodec.h>
+#include <libavcodec/dsputil.h>
 
 /* now this is ripped of wine's vfw.h */
 typedef struct {
