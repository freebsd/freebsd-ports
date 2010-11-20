--- engine/dconf-engine.c.orig	2010-08-04 17:40:53.000000000 +0200
+++ engine/dconf-engine.c	2010-11-03 00:23:07.000000000 +0100
@@ -144,7 +144,7 @@ dconf_engine_setup_user (DConfEngine *en
 
           if (fd >= 0)
             {
-              if (posix_fallocate (fd, 0, 1) == 0)
+              if (ftruncate (fd, 1) == 0)
                 {
                   engine->shm = mmap (NULL, 1, PROT_READ, MAP_SHARED, fd, 0);
 
