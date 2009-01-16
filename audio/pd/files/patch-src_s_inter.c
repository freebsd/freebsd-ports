--- src/s_inter.c.orig	2008-03-15 09:03:00.000000000 +0900
+++ src/s_inter.c	2008-08-23 21:40:09.000000000 +0900
@@ -839,7 +839,7 @@
 
 static int sys_watchfd;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void glob_watchdog(t_pd *dummy)
 {
     if (write(sys_watchfd, "\n", 1) < 1)
@@ -1263,7 +1263,11 @@
              sys_gui("pdtk_watchdog\n");
 #endif
          sys_get_audio_apis(buf);
+#if defined(__FreeBSD__)
+         strcpy(buf2, "{}");
+#else
          sys_get_midi_apis(buf2);
+#endif
          sys_vgui("pdtk_pd_startup {%s} %s %s {%s} %s\n", pd_version, buf, buf2, 
                   sys_font, sys_fontweight); 
     }
@@ -1285,8 +1289,10 @@
 #ifndef __linux__  /* sys_close_audio() hangs if you're in a signal? */
         fprintf(stderr, "closing audio...\n");
         sys_close_audio();
+#if !defined(__FreeBSD__)
         fprintf(stderr, "closing MIDI...\n");
         sys_close_midi();
+#endif
         fprintf(stderr, "... done.\n");
 #endif
         exit(n);
