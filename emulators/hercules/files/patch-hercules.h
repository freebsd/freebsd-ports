--- hercules.h.orig	Mon Sep  2 11:43:46 2002
+++ hercules.h	Mon Sep  2 11:44:56 2002
@@ -333,6 +333,9 @@
         BYTE *iobuf, BYTE *more, BYTE *unitstat, U16 *residual);
 typedef int DEVCF (struct _DEVBLK *dev);
 
+#if defined(HAVE_MTIO_H)
+ #include <sys/mtio.h>
+#endif
 
 /*-------------------------------------------------------------------*/
 /* Structure definition for the Vector Facility                      */
