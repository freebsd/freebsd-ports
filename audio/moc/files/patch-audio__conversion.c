--- audio_conversion.c.orig	Fri Jul 29 10:46:36 2005
+++ audio_conversion.c	Fri Sep  9 12:50:22 2005
@@ -52,6 +52,32 @@
 #include "log.h"
 #include "options.h"
 
+/* FreeBSD 4.x lacks these */
+
+#ifndef INT8_MIN
+#define INT8_MIN	CHAR_MIN
+#endif
+
+#ifndef INT8_MAX
+#define INT8_MAX	CHAR_MAX
+#endif
+
+#ifndef INT16_MIN
+#define INT16_MIN	SHRT_MIN
+#endif
+
+#ifndef INT16_MAX
+#define INT16_MAX	SHRT_MAX
+#endif
+
+#ifndef INT32_MIN
+#define INT32_MIN	INT_MIN
+#endif
+
+#ifndef INT32_MAX
+#define INT32_MAX	INT_MAX
+#endif
+
 /* Byte order conversion */
 /* TODO: use functions from byteswap.h if available */
 #define SWAP_INT16(l) ((int16_t) \
