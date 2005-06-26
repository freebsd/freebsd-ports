--- src/doodle/tree.c.orig	Sun Jun 26 15:13:51 2005
+++ src/doodle/tree.c	Sun Jun 26 15:14:00 2005
@@ -1815,7 +1815,7 @@
     /* make certain that the dirty marker is on
        disk... */
     flush_buffer(ret->fd);
-    fdatasync(ret->fd->fd);
+    fsync(ret->fd->fd);
     ret->modified = 1;
   }
   
