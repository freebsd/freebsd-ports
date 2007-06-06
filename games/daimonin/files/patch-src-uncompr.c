--- ../../src/uncompr.c.orig	Sun May 20 02:10:22 2007
+++ ../../src/uncompr.c	Mon Jun  4 11:40:00 2007
@@ -60,7 +60,7 @@
 
     stream.next_out = dest;
     stream.avail_out = (uInt) * destLen;
-    if ((uLong) stream.avail_out != *destLen)
+    if ((uLong) stream.avail_out != (uInt) *destLen)
         return Z_BUF_ERROR;
 
     stream.zalloc = (alloc_func) 0;
