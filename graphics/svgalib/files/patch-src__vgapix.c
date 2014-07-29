--- src/vgapix.c.orig	1999-07-27 18:36:19.000000000 +0200
+++ src/vgapix.c	2013-01-26 21:14:42.000000000 +0100
@@ -8,6 +8,7 @@
 /* partially copyrighted (C) 1993 by Hartmut Schirmer */
 /* HH: Added 4bpp support, and use bytesperpixel. */
 
+#include <sys/endian.h>
 #include <stdio.h>
 #include "vga.h"
 #include "libvga.h"
@@ -22,21 +23,8 @@ static inline void read_write(unsigned l
 
 static inline int RGB2BGR(int c)
 {
-/* a bswap would do the same as the first 3 but in only ONE! cycle. */
-/* However bswap is not supported by 386 */
-
     if (MODEFLAGS & RGB_MISORDERED)
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
 
