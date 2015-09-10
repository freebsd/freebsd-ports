--- Mix.c.orig	2003-03-27 05:43:11 UTC
+++ Mix.c
@@ -78,7 +78,7 @@ close_mixer() {
 #ifdef DEBUG
   fprintf(stderr, "close_mixer()\n");
 #endif
-  if (mixer_fd < 0) return;
+  if (mixer_fd < 0) return 0;
   close(mixer_fd);
   init_flag = 0;
   mixer_fd = -1;
