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
 static gpointer
 process_thread_func (gpointer data)
 {
@@ -118,6 +121,7 @@
       process_thread = NULL;
     }
 }
+#endif
 
 
 static int
@@ -125,7 +129,9 @@
 {
   g_print ("initializing dummy audio backend\n");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_audio, TRUE);
 
@@ -137,7 +143,9 @@
 {
   g_print ("initializing dummy MIDI backend\n");
 
+#if 0
   start_process_thread ();
+#endif
 
   g_atomic_int_set (&dummy_midi, TRUE);
 
@@ -152,7 +160,9 @@
 
   g_atomic_int_set (&dummy_audio, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
@@ -164,7 +174,9 @@
 
   g_atomic_int_set (&dummy_midi, FALSE);
 
+#if 0
   stop_process_thread ();
+#endif
 
   return 0;
 }
