--- third_party/ffmpeg/libavutil/mem.c.orig	2022-05-19 14:06:27 UTC
+++ third_party/ffmpeg/libavutil/mem.c
@@ -33,9 +33,6 @@
 #include <stdlib.h>
 #include <stdatomic.h>
 #include <string.h>
-#if HAVE_MALLOC_H
-#include <malloc.h>
-#endif
 
 #include "attributes.h"
 #include "avassert.h"
