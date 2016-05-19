--- src/audio/dummybackend.c.orig	2016-04-10 12:10:21 UTC
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
@@ -114,6 +117,7 @@ stop_process_thread ()
       process_thread = NULL;
     }
 }
+#endif
 
 
 static int
@@ -121,7 +125,9 @@ dummy_audio_initialize (DenemoPrefs * co
 {
   g_message ("Initializing dummy audio backend");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_audio, TRUE);
 
@@ -133,7 +139,9 @@ dummy_midi_initialize (DenemoPrefs * con
 {
   g_message ("Initializing dummy MIDI backend");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_midi, TRUE);
 
@@ -148,7 +156,9 @@ dummy_audio_destroy ()
 
   g_atomic_int_set (&dummy_audio, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
@@ -160,7 +170,9 @@ dummy_midi_destroy ()
 
   g_atomic_int_set (&dummy_midi, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
