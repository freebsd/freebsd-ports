--- src/d_array.c.orig	Fri Nov 16 23:57:20 2001
+++ src/d_array.c	Fri May 24 23:12:22 2002
@@ -508,6 +508,19 @@ static void tabread4_tilde_setup(void)
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
+
 #ifdef  __linux__
 #include <endian.h>
 #if !defined(__BYTE_ORDER) || !defined(__LITTLE_ENDIAN)                         
