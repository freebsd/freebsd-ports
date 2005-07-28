--- audio_conversion.c.orig	Wed Jun 15 18:56:46 2005
+++ audio_conversion.c	Fri Jul 29 01:19:15 2005
@@ -27,7 +27,8 @@
 #define __USE_ISOC99    1
 
 #include <assert.h>
-#include <stdint.h>
+#include <inttypes.h>
+#include <limits.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>
@@ -43,6 +44,32 @@
 #include "main.h"
 #include "log.h"
 #include "options.h"
+
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
 
 /* Byte order conversion */
 /* TODO: use functions from byteswap.h if available */
