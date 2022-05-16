--- third_party/ffmpeg/libavutil/mem.c.orig	2021-10-08 06:29:12 UTC
+++ third_party/ffmpeg/libavutil/mem.c
@@ -33,9 +33,6 @@
 #include <stdlib.h>
 #include <stdatomic.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "avutil.h"
 #include "common.h"
