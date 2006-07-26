--- Imager.xs.orig	Wed Jul 26 16:47:45 2006
+++ Imager.xs	Wed Jul 26 16:48:43 2006
@@ -387,7 +387,7 @@
     if (cbd->reading && cbd->where < cbd->used) {
       /* we read past the place where the caller expected us to be
          so adjust our position a bit */
-        *(char *)0 = 0;
+        /* *(char *)0 = 0; debug */
       if (io_seeker(p, cbd->where - cbd->used, SEEK_CUR) < 0) {
         return -1;
       }
