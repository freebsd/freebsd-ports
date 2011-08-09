--- src/s_main.c.orig	2011-03-07 10:11:02.000000000 +0900
+++ src/s_main.c	2011-04-06 19:30:04.000000000 +0900
@@ -300,7 +300,9 @@
     else
     {
             /* open audio and MIDI */
+#if !defined(__FreeBSD__)
         sys_reopen_midi();
+#endif
         sys_reopen_audio();
             /* run scheduler until it quits */
         return (m_mainloop());
@@ -628,7 +630,9 @@
         }
         else if (!strcmp(*argv, "-alsamidi"))
         {
+#if !defined(__FreeBSD__)
           sys_set_midi_api(API_ALSA);
+#endif
             argc--; argv++;
         }
 #endif
@@ -936,7 +940,11 @@
             /* add "doc/5.reference" library to helppath */
     strncpy(sbuf, sys_libdir->s_name, MAXPDSTRING-30);
     sbuf[MAXPDSTRING-30] = 0;
+#if defined(__FreeBSD__)
+    strcat(sbuf, "/share/doc/pd/5.reference");
+#else
     strcat(sbuf, "/doc/5.reference");
+#endif
     sys_helppath = namelist_append_files(sys_helppath, sbuf);
         /* correct to make audio and MIDI device lists zero based.  On
         MMIO, however, "1" really means the second device (the first one
@@ -990,7 +998,9 @@
         for (i = 0; i < naudiooutdev; i++)
             audiooutdev[i] = sys_soundoutdevlist[i];
     }
+#if !defined(__FreeBSD__)
     sys_get_midi_params(&nmidiindev, midiindev, &nmidioutdev, midioutdev);
+#endif
     if (sys_nmidiin >= 0)
     {
         post("sys_nmidiin %d, nmidiindev %d", sys_nmidiin, nmidiindev);
@@ -1015,7 +1025,9 @@
     sys_set_audio_settings(naudioindev, audioindev, nchindev, chindev,
         naudiooutdev, audiooutdev, nchoutdev, choutdev, rate, advance, 
         callback, blocksize);
+#if !defined(__FreeBSD__)
     sys_open_midi(nmidiindev, midiindev, nmidioutdev, midioutdev, 0);
+#endif
 }
 
 static void sys_addreferencepath(void)
