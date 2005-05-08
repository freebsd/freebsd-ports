--- srcore/srspc.c.orig	Sun May  8 01:10:29 2005
+++ srcore/srspc.c	Sun May  8 01:10:37 2005
@@ -1531,8 +1531,8 @@ src_timeout_start_speech (gpointer data)
 static void
 src_restart_speech ()
 {
-    g_printerr ("\nRestarting speech.\n");
     gboolean use_speech = FALSE;
+    g_printerr ("\nRestarting speech.\n");
     SET_SRCORE_CONFIG_DATA (SRCORE_SPEECH_ACTIVE, CFGT_BOOL, &use_speech);
     g_timeout_add (SRC_SPEECH_RESTART_TIMEOUT, src_timeout_start_speech, NULL);
 }
