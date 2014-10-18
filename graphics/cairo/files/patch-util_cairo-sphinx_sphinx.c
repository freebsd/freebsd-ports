--- util/cairo-sphinx/sphinx.c.orig	2014-10-06 15:22:24.000000000 -0400
+++ util/cairo-sphinx/sphinx.c	2014-10-06 15:23:04.000000000 -0400
@@ -1325,7 +1325,7 @@ client_shm (const char *shm_path)
 
     base = mmap (NULL, DATA_SIZE,
 		 PROT_READ | PROT_WRITE,
-		 MAP_SHARED | MAP_NORESERVE,
+		 MAP_SHARED,
 		 fd, 0);
     close (fd);
 
