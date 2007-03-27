--- src/s_file.c.orig	Sat Dec 31 21:08:37 2005
+++ src/s_file.c	Sun Mar 25 01:47:57 2007
@@ -339,7 +339,7 @@
             break;
         nmidioutdev++;
     }
-    sys_open_midi(nmidiindev, midiindev, nmidioutdev, midioutdev, 0);
+//    sys_open_midi(nmidiindev, midiindev, nmidioutdev, midioutdev, 0);
 
         /* search path */
     if (sys_getpreference("npath", prefbuf, MAXPDSTRING))
@@ -397,8 +397,8 @@
     int naudiooutdev, audiooutdev[MAXAUDIOOUTDEV], choutdev[MAXAUDIOOUTDEV];
     int i, rate, advance;
     char buf1[MAXPDSTRING], buf2[MAXPDSTRING];
-    int nmidiindev, midiindev[MAXMIDIINDEV];
-    int nmidioutdev, midioutdev[MAXMIDIOUTDEV];
+//    int nmidiindev, midiindev[MAXMIDIINDEV];
+//    int nmidioutdev, midioutdev[MAXMIDIOUTDEV];
 
     sys_initsavepreferences();
 
@@ -431,7 +431,7 @@
     sprintf(buf1, "%d", rate);
     sys_putpreference("rate", buf1);
 
-        /* MIDI settings */
+        /* MIDI settings
     sys_get_midi_params(&nmidiindev, midiindev, &nmidioutdev, midioutdev);
     sys_putpreference("nomidiin", (nmidiindev <= 0 ? "True" : "False"));
     for (i = 0; i < nmidiindev; i++)
@@ -447,6 +447,7 @@
         sprintf(buf2, "%d", midioutdev[i]);
         sys_putpreference(buf1, buf2);
     }
+    */
         /* file search path */
 
     for (i = 0; 1; i++)
