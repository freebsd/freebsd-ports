--- src/curses/ux_audio_oss.c.orig	2014-03-06 06:08:15 UTC
+++ src/curses/ux_audio_oss.c
@@ -80,7 +80,7 @@ static void sigterm_handler(int signal) 
   _exit(0);
 }
 
-static void sigint_handler(int signal) {
+static void oss_sigint_handler(int signal) {
   num_repeats = 1;
 }
 
@@ -141,7 +141,7 @@ static void play_sound(int volume, int r
   sigaddset(&sa.sa_mask, SIGTERM);
   sa.sa_flags = 0;
   sigaction(SIGTERM, &sa, NULL);
-  sa.sa_handler = sigint_handler;
+  sa.sa_handler = oss_sigint_handler;
   sigaction(SIGINT, &sa, NULL);
 
   for (num_repeats = repeats; num_repeats > 0;
