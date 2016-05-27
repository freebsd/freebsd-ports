--- src/export/exportlilypond.c.orig	2016-04-10 12:10:21 UTC
+++ src/export/exportlilypond.c
@@ -2959,9 +2959,11 @@ goto_lilypond_position (gint line, gint 
  if (gui->lilysync != gui->changecount)
       refresh_lily_cb (NULL, gui);
 
+#ifdef USE_EVINCE  
  if (printview_is_stale ())
       play_note (DEFAULT_BACKEND, 0, 9, 69, 300, 100);
   //g_print ("goto_lilypond_position called for line %d column %d\n", line, column);
+#endif
 
   gtk_text_buffer_get_end_iter (Denemo.textbuffer, &enditer);
   gtk_text_buffer_get_start_iter (Denemo.textbuffer, &iter);
