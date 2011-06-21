--- ./Mix.c.orig	2011-06-21 21:06:03.000000000 +0200
+++ ./Mix.c	2011-06-21 21:06:53.000000000 +0200
@@ -78,7 +78,7 @@
 #ifdef DEBUG
   fprintf(stderr, "close_mixer()\n");
 #endif
-  if (mixer_fd < 0) return;
+  if (mixer_fd < 0) return 0;
   close(mixer_fd);
   init_flag = 0;
   mixer_fd = -1;
