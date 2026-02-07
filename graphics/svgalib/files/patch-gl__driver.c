--- gl/driver.c.orig	1999-07-18 10:18:44.000000000 +0200
+++ gl/driver.c	2013-01-26 21:34:27.000000000 +0100
@@ -1,6 +1,7 @@
 /* driver.c     Framebuffer primitives */
 
 
+#include <sys/endian.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -33,17 +34,7 @@ static inline int RGB2BGR(int c)
 /* However bswap is not supported by 386 */
 
     if (MODEFLAGS & MODEFLAG_24BPP_REVERSED)
-#ifdef __alpha__
-	c = ((c >> 0) & 0xff) << 16 |
-	    ((c >> 8) & 0xff) << 8 |
-	    ((c >> 16) & 0xff) << 0;
-#else
-	asm("rorw  $8, %0\n"	/* 0RGB -> 0RBG */
-	    "rorl $16, %0\n"	/* 0RBG -> BG0R */
-	    "rorw  $8, %0\n"	/* BG0R -> BGR0 */
-	    "shrl  $8, %0\n"	/* 0BGR -> 0BGR */
-      : "=q"(c):"0"(c));
-#endif
+	c = bswap32(c) >> 8;
     return c;
 }
 
