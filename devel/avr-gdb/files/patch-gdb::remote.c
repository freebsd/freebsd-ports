--- remote.c.orig	Sat Nov  6 00:38:25 2004
+++ remote.c	Tue May 24 21:34:59 2005
@@ -4895,8 +4895,10 @@
 	return -1;
     }
 
-  /* Only handle reads.  */
-  if (writebuf != NULL || readbuf == NULL)
+  /* Only handle reads.  Zero OFFSET and LENGTH is just a size
+   * query only, so allow it anyway.  */
+  if ((writebuf != NULL || readbuf == NULL) &&
+      !(offset == 0 && len == 0))
     return -1;
 
   /* Map pre-existing objects onto letters.  DO NOT do this for new
