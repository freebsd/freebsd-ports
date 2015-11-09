--- util/cairo-sphinx/sphinx.c.orig	2015-03-10 22:21:07 UTC
+++ util/cairo-sphinx/sphinx.c
@@ -1337,7 +1337,7 @@ client_shm (const char *shm_path)
 
     base = mmap (NULL, DATA_SIZE,
 		 PROT_READ | PROT_WRITE,
-		 MAP_SHARED | MAP_NORESERVE,
+		 MAP_SHARED,
 		 fd, 0);
     close (fd);
 
