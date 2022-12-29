--- third_party/ffmpeg/libavutil/random_seed.c.orig	2022-02-07 13:39:41 UTC
+++ third_party/ffmpeg/libavutil/random_seed.c
@@ -30,6 +30,11 @@
 #include <windows.h>
 #include <bcrypt.h>
 #endif
+#if HAVE_ARC4RANDOM
+#undef __BSD_VISIBLE
+#define __BSD_VISIBLE 1
+#include <stdlib.h>
+#endif
 #include <fcntl.h>
 #include <math.h>
 #include <time.h>
