--- extra/paf~/paf~.c.orig	Wed Mar  6 18:58:30 2002
+++ extra/paf~/paf~.c	Fri May 24 23:15:15 2002
@@ -161,6 +161,20 @@ static void linenv_set(t_linenv *l, floa
 #define DONE_MACHINE_TYPE
 #endif /* MACOSX */
 
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
+#define DONE_MACHINE_TYPE
+#endif /* __FreeBSD__ */
+
 #ifdef  __linux__
 
 #include <endian.h>
