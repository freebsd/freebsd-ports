--- aplay/aplay.c.orig	2020-02-19 12:02:10 UTC
+++ aplay/aplay.c
@@ -49,7 +49,6 @@
 #include <sys/time.h>
 #include <sys/stat.h>
 #include <sys/types.h>
-#include <endian.h>
 #include "gettext.h"
 #include "formats.h"
 #include "version.h"
@@ -70,6 +69,12 @@
 #define be16toh(x) __be16_to_cpu(x)
 #define le32toh(x) __le32_to_cpu(x)
 #define be32toh(x) __be32_to_cpu(x)
+#endif
+
+#ifndef _LARGEFILE64_SOURCE
+/* assume modern system */
+typedef off_t off64_t;
+#define lseek64 lseek
 #endif
 
 #define DEFAULT_FORMAT		SND_PCM_FORMAT_U8
