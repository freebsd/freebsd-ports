diff --git module/ffdecode.c module/ffdecode.c
index e9e0db7..c32a788 100644
--- module/ffdecode.c
+++ module/ffdecode.c
@@ -22,6 +22,7 @@
 #include <math.h>
 #include <limits.h>
 #include <libavutil/avstring.h>
+#include <libavutil/time.h>
 #include <libavformat/avformat.h>
 #include <libavcodec/avcodec.h>
 #include <libswscale/swscale.h>
