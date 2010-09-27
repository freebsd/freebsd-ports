--- ../../src/uncompr.c.orig	2010-09-19 10:32:48.000000000 -0400
+++ ../../src/uncompr.c	2010-09-19 10:35:17.000000000 -0400
@@ -37,7 +37,7 @@
 
     stream.next_out = dest;
     stream.avail_out = (uInt)*destLen;
-    if ((uLong)stream.avail_out != *destLen) return Z_BUF_ERROR;
+    if ((uLong)stream.avail_out != (uLong)*destLen) return Z_BUF_ERROR;
 
     stream.zalloc = (alloc_func)0;
     stream.zfree = (free_func)0;
