--- mpeglib/lib/util/render/dither2YUV/rgb2yuvdefs.h.orig	Tue Sep  2 07:04:27 2003
+++ mpeglib/lib/util/render/dither2YUV/rgb2yuvdefs.h	Wed Aug  4 12:48:40 2004
@@ -20,6 +20,9 @@
 
 /* gcc 3.3.1 and later optimise the "not used" (only in asm code)
    symbols away. So we need to mark them as used. */
+#if defined(__GNUC_PREREQ__) && !defined(__GNUC_PREREQ)
+#define __GNUC_PREREQ __GNUC_PREREQ__
+#endif
 #ifdef __GNUC_PREREQ
 #if __GNUC_PREREQ (3,1)
 # define __attribute_used__ __attribute__ ((__used__))