--- plugins/soundsourcem4a/soundsourcem4a.h.orig	2019-07-19 22:36:09 UTC
+++ plugins/soundsourcem4a/soundsourcem4a.h
@@ -5,6 +5,8 @@
 
 #include "util/readaheadsamplebuffer.h"
 
+#include <sys/types.h>
+
 #ifdef __MP4V2__
 #include <mp4v2/mp4v2.h>
 #else
