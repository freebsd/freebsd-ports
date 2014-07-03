--- ./contrib/ffmpeg-strip-wma/common.h.orig	2014-07-02 10:52:02.000000000 -0400
+++ ./contrib/ffmpeg-strip-wma/common.h	2014-07-02 10:52:39.000000000 -0400
@@ -1150,11 +1150,6 @@
 
 #define CLAMP_TO_8BIT(d) ((d > 0xff) ? 0xff : (d < 0) ? 0 : d)
 
-/* avoid usage of various functions */
-#define malloc please_use_av_malloc
-#define free please_use_av_free
-#define realloc please_use_av_realloc
-
 #define CHECKED_ALLOCZ(p, size)\
 {\
     p= av_mallocz(size);\
