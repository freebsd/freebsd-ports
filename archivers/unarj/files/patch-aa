--- unarj.h.orig	Mon Sep 29 14:00:24 1997
+++ unarj.h	Thu Feb 18 01:06:10 1999
@@ -106,8 +106,12 @@
 #endif
 
 typedef unsigned char  uchar;   /*  8 bits or more */
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 typedef unsigned int   uint;    /* 16 - 32 bits or more */
 typedef unsigned short ushort;  /* 16 bits or more */
+#else
+#  include <sys/types.h>
+#endif
 typedef unsigned long  ulong;   /* 32 bits or more */
 
 #define USHRT_BIT   (CHAR_BIT * sizeof(ushort))
