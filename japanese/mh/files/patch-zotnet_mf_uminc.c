--- zotnet/mf/uminc.c.orig
+++ zotnet/mf/uminc.c
@@ -86,7 +86,6 @@
     int     clear,
             count,
             fd;
-    extern int  errno;
     struct stat stbuf;
 
     for (clear = FALSE, count = 2; count > 0; count--)
