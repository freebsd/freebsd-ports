--- lib/hostip.c.orig	Tue May 13 05:12:17 2003
+++ lib/hostip.c	Sun Jun 15 18:44:13 2003
@@ -497,11 +497,11 @@
 
   /* now, shrink the allocated buffer to the size we actually need, which
      most often is only a fraction of the original alloc */
-  newbuf=(char *)realloc(*buf, (int)bufptr-(int)(*buf));
+  newbuf=(char *)realloc(*buf, (int)(bufptr-*buf));
 
   /* if the alloc moved, we need to adjust things again */
   if(newbuf != *buf)
-    hostcache_fixoffset((struct hostent*)newbuf, (int)newbuf-(int)*buf);
+    hostcache_fixoffset((struct hostent*)newbuf, (int)(newbuf-*buf));
 
   /* setup the return */
   *buf = newbuf;
