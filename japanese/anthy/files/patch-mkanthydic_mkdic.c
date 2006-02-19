--- mkanthydic/mkdic.c.orig	Sun Feb 19 20:11:14 2006
+++ mkanthydic/mkdic.c	Sun Feb 19 20:11:38 2006
@@ -121,7 +121,7 @@
       if (fd == -1) {
 	*(fs->fpp) = NULL;
       } else {
-	*(fs->fpp) = fdopen(fd, "w");
+	*(fs->fpp) = fdopen(fd, "w+");
 	unlink(buf);
       }
     } else {
