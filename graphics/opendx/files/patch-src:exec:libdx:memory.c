--- src/exec/libdx/memory.c.orig	Mon May 21 07:06:59 2001
+++ src/exec/libdx/memory.c	Thu Oct 11 10:15:47 2001
@@ -1057,6 +1057,19 @@
 #define LARGE(x) ((int)x>=(int)large)
 #endif
 
+#ifdef	freebsd
+#define initvalues
+#define SMALL_BASE    0               /* use data segment */
+#define SMALL_GET     _dxfgetmem      /* expand by using DosSetMem */
+#define LARGE_GET     _dxfgetmem      /* expand by using DosSetMem */
+#define LARGE_INIT    2 MEG           /* doesn't matter; consistent w/ sgi */
+#define LARGE_INCR    2 MEG           /* doesn't matter; consistent w/ sgi */
+#define SIZE_ROUND    2 MEG           /* doesn't matter; consistent w/ sgi */
+#define MALLOC_NONE   1               /* provide malloc from global arena */
+#define SMALL(x) ((long)x<(long)large)
+#define LARGE(x) ((long)x>=(long)large)
+#endif
+
 #ifdef	cygwin
 #define initvalues
 #define SMALL_BASE    0               /* use data segment */
