--- src/unexelf.c.orig	2015-08-22 16:05:06 UTC
+++ src/unexelf.c
@@ -1323,7 +1323,7 @@ temacs:
   if (stat (new_name, &stat_buf) != 0)
     fatal ("Can't stat (%s): %s", new_name, strerror (errno));
 
-  mask = umask (777);
+  mask = umask (0777);
   umask (mask);
   stat_buf.st_mode |= 0111 & ~mask;
   if (chmod (new_name, stat_buf.st_mode) != 0)
