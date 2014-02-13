--- ./freeze.h.orig	1993-02-24 14:36:58.000000000 +0100
+++ ./freeze.h	2014-02-13 12:43:34.947977110 +0100
@@ -5,21 +5,6 @@
 # include <sys/stdtypes.h>
 #endif
 
-#ifndef getc
-# ifdef m88k                   /* Green Hill C library bug. */
-#  define getc(p)         (--(p)->_cnt < 0 ? __filbuf(p) : (int) *(p)->_ptr++)
-# else
-#  define getc(p)         (--(p)->_cnt < 0 ? _filbuf(p) : (int) *(p)->_ptr++)
-# endif
-#endif
-#ifndef putc
-# ifdef m88k                   /* Green Hill C library bug. */
-#  define putc(x, p)      (--(p)->_cnt < 0 ? __flsbuf((unsigned char) (x), (p)) : (int) (*(p)->_ptr++ = (unsigned char) (x)))
-# else
-#  define putc(x, p)      (--(p)->_cnt < 0 ? _flsbuf((unsigned char) (x), (p)) : (int) (*(p)->_ptr++ = (unsigned char) (x)))
-# endif
-#endif
-
 #if !defined(MSDOS) && defined(__MSDOS__)
 # define MSDOS
 #endif
