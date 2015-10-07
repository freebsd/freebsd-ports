--- contrib/ffmpeg-strip-wma/common.h.orig	2012-06-28 14:58:11 UTC
+++ contrib/ffmpeg-strip-wma/common.h
@@ -1150,11 +1150,6 @@ if(256*256*256*64%(tcount+tskip_count)==
 
 #define CLAMP_TO_8BIT(d) ((d > 0xff) ? 0xff : (d < 0) ? 0 : d)
 
-/* avoid usage of various functions */
-#define malloc please_use_av_malloc
-#define free please_use_av_free
-#define realloc please_use_av_realloc
-
 #define CHECKED_ALLOCZ(p, size)\
 {\
     p= av_mallocz(size);\
