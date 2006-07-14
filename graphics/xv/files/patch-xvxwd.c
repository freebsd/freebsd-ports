--- xvxwd.c.orig	Sun Jul  9 18:12:45 2006
+++ xvxwd.c	Mon Jul 10 20:04:55 2006
@@ -19,7 +19,7 @@
  */
 
 #include "xv.h"
-
+#include <sys/endian.h>
 
 /***************************** x11wd.h *****************************/
 #define X11WD_FILE_VERSION 7
@@ -66,23 +66,30 @@
 
 typedef byte pixel;
 
+#if __FreeBSD_cc_version < 500000
+static CARD16	bs_short(CARD16 x);
+static CARD32	bs_long(CARD32 x);
+#else
+#define    bs_short(x)	bswap16(x)
+#define    bs_long(x)	bswap32(x)
+#endif
+
 /* local functions */
 static int    getinit         PARM((FILE *, int*, int*, int*, CARD32 *, 
 			                          CARD32, PICINFO *));
 static CARD32 getpixnum       PARM((FILE *));
 static int    xwdError        PARM((char *));
 static void   xwdWarning      PARM((char *));
-static int    bs_short        PARM((int));
-static CARD32 bs_long         PARM((CARD32));
 static int    readbigshort    PARM((FILE *, CARD16 *));
 static int    readbiglong     PARM((FILE *, CARD32 *));
 static int    readlittleshort PARM((FILE *, CARD16 *));
 static int    readlittlelong  PARM((FILE *, CARD32 *));
 static int    writebigshort   PARM((FILE *, int));
 static int    writebiglong    PARM((FILE *, CARD32));
-
+static int    get_shift       PARM((CARD32));
 static byte  *pic8, *pic24;
 static CARD32 red_mask, green_mask, blue_mask;
+static int    red_shift, green_shift, blue_shift;
 static int    bits_per_item, bits_used, bit_shift, bits_per_pixel;
 static char   buf[4];
 static char   *byteP;
@@ -181,24 +188,9 @@
 	CARD32 ul;
 	
 	ul = getpixnum(ifp);
-	switch (bits_per_pixel) {
-	case 16:
-	  *xP++ = ((ul & red_mask)   >> 0);
-	  *xP++ = ((ul & green_mask) >> 5);
-	  *xP++ = ((ul & blue_mask)  >> 10);
-	  break;
-	  
-	case 24:
-	case 32:
-	  *xP++ = (ul    ) & 0xff;
-	  *xP++ = (ul>> 8) & 0xff;
-	  *xP++ = (ul>>16) & 0xff;
-	  break;
-	  
-	default:
-	  xwdError("True/Direct only supports 16, 24, and 32 bits");
-	  return 0;
-	}
+	*xP++ = ((ul & red_mask)   << red_shift) >> 24;
+	*xP++ = ((ul & green_mask) << green_shift) >> 24;
+	*xP++ = ((ul & blue_mask)  << blue_shift) >> 24;
       }
 
       for (col=0; col<padright; col++) getpixnum(ifp);
@@ -266,6 +258,8 @@
     byte_swap = 1;
     h11P->header_size      = bs_long(h11P->header_size);
     h11P->file_version     = bs_long(h11P->file_version);
+    if (h11P->file_version != X11WD_FILE_VERSION)
+	return(xwdError("unsupported X11 XWD file version"));
     h11P->pixmap_format    = bs_long(h11P->pixmap_format);
     h11P->pixmap_depth     = bs_long(h11P->pixmap_depth);
     h11P->pixmap_width     = bs_long(h11P->pixmap_width);
@@ -427,6 +421,10 @@
   green_mask = h11P->green_mask;
   blue_mask  = h11P->blue_mask;
 
+  red_shift   = get_shift(red_mask);
+  green_shift = get_shift(green_mask);
+  blue_shift  = get_shift(blue_mask);
+
   byteP  = (char   *) buf;
   shortP = (CARD16 *) buf;
   longP  = (CARD32 *) buf;
@@ -534,39 +532,21 @@
  * Byte-swapping junk.
  */
 
-union cheat {
-  CARD32 l;
-  CARD16 s;
-  CARD8  c[sizeof(CARD32)];
-};
-
-static int bs_short(s)
-     int s;
+#if __FreeBSD_cc_version < 500000
+static CARD32   bs_long(CARD32 x)
 {
-  union cheat u;
-  unsigned char t;
-
-  u.s = (CARD16) s;
-  t = u.c[0];  u.c[0] = u.c[1];  u.c[1] = t;
-  return (int) u.s;
+  return (((x & 0xff000000U) >> 24) |
+          ((x & 0x00ff0000U) >>  8) |
+          ((x & 0x0000ff00U) <<  8) |
+          ((x & 0x000000ffU) << 24));
 }
 
-static CARD32 bs_long(l)
-     CARD32 l;
+
+static CARD16   bs_short(CARD16 x)
 {
-  union cheat u;
-  unsigned char t;
-  
-  u.l = l;
-  t = u.c[0];  u.c[0] = u.c[3];  u.c[3] = t;
-  t = u.c[1];  u.c[1] = u.c[2];  u.c[2] = t;
-  return u.l;
+  return (((x & 0xff00U) >> 8) | ((x & 0x00ffU) << 8));
 }
-
-
-
-
-
+#endif
 
 /* 
  * Endian I/O.
@@ -623,7 +603,7 @@
 }
 
 
-static int writebiglong(out, l)
+	static int writebiglong(out, l)
      FILE* out;
      CARD32 l;
 {
@@ -642,4 +622,17 @@
   putc((s>>8)&0xff, out);
   putc(s&0xff, out);
   return 0;
+}
+
+
+static int get_shift(val)
+    CARD32 val;
+{
+    int		shift;
+
+if (!val)
+	return (0);
+    for (shift = 0; !(val & 0x80000000); shift++)
+	val <<= 1;
+    return (shift);
 }

