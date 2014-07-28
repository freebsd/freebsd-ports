--- xdigger.c	Thu Jan  1 00:06:00 1998
+++ /home/andy/tmp/wrk/xdigger.c	Sat Jun 29 23:19:18 1996
@@ -311,17 +315,29 @@
 
   Fill_TonBuffer(TON_AUDIO_LOW, TON_AUDIO_HIGH, TON_AUDIO_RATE, True);
 
+#ifdef __FreeBSD__
+  fd = open(XDIGGER_LIB_DIR "/diamond.au", O_CREAT | O_WRONLY);
+#else
   fd = open("audio/diamond.au", O_CREAT | O_WRONLY);
+#endif
   fchmod(fd, 0644);
   write(fd, &ton_buffer[TON_DIAMANT], ton_laenge[TON_DIAMANT]+24);
   close(fd);
 
+#ifdef __FreeBSD__
+  fd = open(XDIGGER_LIB_DIR "/stone.au", O_CREAT | O_WRONLY);
+#else
   fd = open("audio/stone.au", O_CREAT | O_WRONLY);
+#endif
   fchmod(fd, 0644);
   write(fd, &ton_buffer[TON_STEINE], ton_laenge[TON_STEINE]+24);
   close(fd);
 
+#ifdef __FreeBSD__
+  fd = open(XDIGGER_LIB_DIR "/step.au", O_CREAT | O_WRONLY);
+#else
   fd = open("audio/step.au", O_CREAT | O_WRONLY);
+#endif
   fchmod(fd, 0644);
   write(fd, &ton_buffer[TON_SCHRITT], ton_laenge[TON_SCHRITT]+24);
   close(fd);
@@ -338,7 +354,7 @@
 {
   printf("Usage: xdigger [-display display] [-1|2|3|...] [-noblink] [-noiconmove] [-vert240] [-sound ");
 #ifdef SOUND_DSP_AUDIO
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
   printf("dsp|");
 #endif
   printf("audio|");
@@ -390,7 +406,7 @@
             }
 #endif            
 #ifdef SOUND_DSP_AUDIO
-#ifdef linux
+#if ( defined(linux) || defined(__FreeBSD__) )
             if(!strcmp(argv[i], "dsp")) sound_device = SD_DSP; else
 #endif
             if(!strcmp(argv[i], "audio")) sound_device = SD_AUDIO; else
