--- src/s_main.c.orig	Wed Sep 27 19:22:35 2006
+++ src/s_main.c	Sun Mar 25 19:47:12 2007
@@ -310,7 +310,7 @@
     else
     {
             /* open audio and MIDI */
-        sys_reopen_midi();
+//      sys_reopen_midi();
         sys_reopen_audio();
             /* run scheduler until it quits */
         return (m_scheduler());
@@ -635,7 +635,7 @@
         }
         else if (!strcmp(*argv, "-alsamidi"))
         {
-          sys_set_midi_api(API_ALSA);
+//          sys_set_midi_api(API_ALSA);
             argc--; argv++;
         }
 #endif
@@ -904,7 +904,7 @@
             /* add "doc/5.reference" library to helppath */
     strncpy(sbuf, sys_libdir->s_name, MAXPDSTRING-30);
     sbuf[MAXPDSTRING-30] = 0;
-    strcat(sbuf, "/doc/5.reference");
+    strcat(sbuf, "/share/doc/pd/5.reference");
     sys_helppath = namelist_append_files(sys_helppath, sbuf);
         /* correct to make audio and MIDI device lists zero based.  On
         MMIO, however, "1" really means the second device (the first one
@@ -957,7 +957,7 @@
         for (i = 0; i < naudiooutdev; i++)
             audiooutdev[i] = sys_soundoutdevlist[i];
     }
-    sys_get_midi_params(&nmidiindev, midiindev, &nmidioutdev, midioutdev);
+//    sys_get_midi_params(&nmidiindev, midiindev, &nmidioutdev, midioutdev);
     if (sys_nmidiin >= 0)
     {
         post("sys_nmidiin %d, nmidiindev %d", sys_nmidiin, nmidiindev);
@@ -977,7 +977,7 @@
         rate = sys_main_srate;
     sys_open_audio(naudioindev, audioindev, nchindev, chindev,
         naudiooutdev, audiooutdev, nchoutdev, choutdev, rate, advance, 0);
-    sys_open_midi(nmidiindev, midiindev, nmidioutdev, midioutdev, 0);
+//    sys_open_midi(nmidiindev, midiindev, nmidioutdev, midioutdev, 0);
 }
 
 static void sys_addreferencepath(void)
