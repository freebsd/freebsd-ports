--- lib/hostip.c.orig	Fri Apr  9 14:28:07 2004
+++ lib/hostip.c	Fri Apr  9 14:29:12 2004
@@ -887,11 +887,11 @@
 
   /* now, shrink the allocated buffer to the size we actually need, which
      most often is only a fraction of the original alloc */
-  newbuf=(char *)realloc(*buf, (long)bufptr-(long)(*buf));
+  newbuf=(char *)realloc(*buf, (long)(bufptr-*buf));
 
   /* if the alloc moved, we need to adjust things again */
   if(newbuf != *buf)
-    hostcache_fixoffset((struct hostent*)newbuf, (long)newbuf-(long)*buf);
+    hostcache_fixoffset((struct hostent*)newbuf, (long)(newbuf-*buf));
 
   /* setup the return */
   *buf = newbuf;
