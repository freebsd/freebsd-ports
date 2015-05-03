--- src/audio/dummybackend.c.orig	2015-02-09 02:55:09 UTC
+++ src/audio/dummybackend.c
@@ -21,9 +21,11 @@
 static int const PLAYBACK_INTERVAL = 100000;
 
 
+#if 0
 static GThread *process_thread = NULL;
 static GCond *process_cond = NULL;
 static gboolean quit_thread = FALSE;
+#endif
 
 static gboolean dummy_audio = FALSE;
 static gboolean dummy_midi = FALSE;
@@ -31,6 +33,7 @@ static gboolean dummy_midi = FALSE;
 static double playback_start_time;
 
 
+#if 0
 static gpointer
 process_thread_func (gpointer data)
 {
@@ -117,6 +120,7 @@ stop_process_thread ()
       process_thread = NULL;
     }
 }
+#endif
 
 
 static int
@@ -124,7 +128,9 @@ dummy_audio_initialize (DenemoPrefs * co
 {
   g_message ("Initializing dummy audio backend");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_audio, TRUE);
 
@@ -136,7 +142,9 @@ dummy_midi_initialize (DenemoPrefs * con
 {
   g_message ("Initializing dummy MIDI backend");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_midi, TRUE);
 
@@ -151,7 +159,9 @@ dummy_audio_destroy ()
 
   g_atomic_int_set (&dummy_audio, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
@@ -163,7 +173,9 @@ dummy_midi_destroy ()
 
   g_atomic_int_set (&dummy_midi, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
