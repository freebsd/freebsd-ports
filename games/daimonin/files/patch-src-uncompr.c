--- ../../src/uncompr.c.orig	Sun Nov 30 22:59:30 2003
+++ ../../src/uncompr.c	Wed Feb 16 22:11:32 2005
@@ -39,7 +39,7 @@
 
     stream.next_out = dest;
     stream.avail_out = (uInt)*destLen;
-    if ((uLong)stream.avail_out != *destLen) return Z_BUF_ERROR;
+    if ((uLong)stream.avail_out != (uInt)*destLen) return Z_BUF_ERROR;
 
     stream.zalloc = (alloc_func)0;
     stream.zfree = (free_func)0;
