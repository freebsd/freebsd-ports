--- as/const.h.orig	1993-07-10 16:04:48 UTC
+++ as/const.h
@@ -1,5 +1,9 @@
 #define align(x)		/* ((x) = ((int) (x) + (4-1)) & ~(4-1)) */
-#define LOW_BYTE	0	/* must be changed for big-endian */
+#if __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#define LOW_BYTE	(sizeof (offset_t) - 1)
+#else
+#define LOW_BYTE	0
+#endif
 
 /* const.h - constants for assembler */
 
