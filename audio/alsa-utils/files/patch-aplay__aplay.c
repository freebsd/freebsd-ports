--- aplay/aplay.c~
+++ aplay/aplay.c
@@ -48,7 +48,6 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <endian.h>
 #include "aconfig.h"
 #include "gettext.h"
 #include "formats.h"
@@ -70,6 +69,12 @@
 #define be32toh(x) __be32_to_cpu(x)
 #endif
 
+#ifndef _LARGEFILE64_SOURCE
+/* assume modern system */
+typedef off_t off64_t;
+#define lseek64 lseek
+#endif
+
 #define DEFAULT_FORMAT		SND_PCM_FORMAT_U8
 #define DEFAULT_SPEED 		8000
 
