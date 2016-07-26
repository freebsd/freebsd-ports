--- ar.h.orig	1993-05-01 04:04:22 UTC
+++ ar.h
@@ -15,10 +15,12 @@ Adapted from "ar" archiver written by Ha
 /* uchar should be 8 bits or more */
 /* typedef unsigned char  uchar;   -- already in zoo.h */
 
+#if !(defined(__FreeBSD__) && __FreeBSD__ < 3) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 typedef unsigned int   uint;    /* 16 bits or more */
 #if !defined(__386BSD__) || !defined(_TYPES_H_)
 typedef unsigned short ushort;  /* 16 bits or more */
 #endif
+#endif
 typedef unsigned long  ulong;   /* 32 bits or more */
 
 /* T_UINT16 must be #defined in options.h to be 
