--- src/dummybackend.c.orig
+++ src/dummybackend.c
@@ -21,9 +21,11 @@
 static int const PLAYBACK_INTERVAL = 100000;
 
 
+#if 0
 static GThread *process_thread = NULL;
 static GCond *process_cond = NULL;
 static gboolean quit_thread = FALSE;
+#endif
 
 static gboolean dummy_audio = FALSE;
 static gboolean dummy_midi = FALSE;
@@ -31,6 +33,7 @@
 static double playback_start_time;
 
 
+#if 0
 static gpointer process_thread_func(gpointer data) {
   GMutex *mutex = g_mutex_new();
 
@@ -102,12 +105,15 @@
     process_thread = NULL;
   }
 }
+#endif
 
 
 static int dummy_audio_initialize(DenemoPrefs *config) {
   g_print("initializing dummy audio backend\n");
 
+#if 0
   start_process_thread();
+#endif
 
   g_atomic_int_set(&dummy_audio, TRUE);
 
@@ -117,7 +123,9 @@
 static int dummy_midi_initialize(DenemoPrefs *config) {
   g_print("initializing dummy MIDI backend\n");
 
+#if 0
   start_process_thread();
+#endif
 
   g_atomic_int_set(&dummy_midi, TRUE);
 
@@ -130,7 +138,9 @@
 
   g_atomic_int_set(&dummy_audio, FALSE);
 
+#if 0
   stop_process_thread();
+#endif
 
   return 0;
 }
@@ -140,7 +150,9 @@
 
   g_atomic_int_set(&dummy_midi, FALSE);
 
+#if 0
   stop_process_thread();
+#endif
 
   return 0;
 }
