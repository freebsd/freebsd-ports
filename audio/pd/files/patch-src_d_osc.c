--- src/d_osc.c.orig	Fri Nov 16 23:57:14 2001
+++ src/d_osc.c	Fri May 24 23:12:26 2002
@@ -24,6 +24,18 @@
 #define LOWOFFSET 0
 #define int32 long
 #else
+#ifdef __FreeBSD__
+#include <machine/endian.h>
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define HIOFFSET 1
+#define LOWOFFSET 0
+#else
+#define HIOFFSET 0    /* word offset to find MSB */
+#define LOWOFFSET 1    /* word offset to find LSB */
+#endif /* BYTE_ORDER */
+#include <sys/types.h>
+#define int32 int32_t
+#endif
 #ifdef __linux__
 
 #include <endian.h>
