--- src/s_inter.c.orig	Tue Aug 15 07:03:09 2006
+++ src/s_inter.c	Sun Mar 25 13:03:16 2007
@@ -831,7 +831,7 @@
 
 static int sys_watchfd;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 void glob_watchdog(t_pd *dummy)
 {
     if (write(sys_watchfd, "\n", 1) < 1)
@@ -1247,7 +1247,8 @@
              sys_gui("pdtk_watchdog\n");
 #endif
          sys_get_audio_apis(buf);
-         sys_get_midi_apis(buf2);
+//         sys_get_midi_apis(buf2);
+	 strcpy(buf2, "{}");
          sys_vgui("pdtk_pd_startup {%s} %s %s {%s}\n", pd_version, buf, buf2,
                                   sys_font); 
     }
@@ -1269,8 +1270,8 @@
 #ifndef __linux__  /* sys_close_audio() hangs if you're in a signal? */
         fprintf(stderr, "closing audio...\n");
         sys_close_audio();
-        fprintf(stderr, "closing MIDI...\n");
-        sys_close_midi();
+//      fprintf(stderr, "closing MIDI...\n");
+//      sys_close_midi();
         fprintf(stderr, "... done.\n");
 #endif
         exit(n);
