--- src/game_gui.c.orig	Sat Sep 10 11:30:49 2005
+++ src/game_gui.c	Sat Oct  8 18:01:30 2005
@@ -425,6 +425,10 @@
     return FALSE;
 }
 
+void print_test(gpointer data) {
+	game_gui_print_message((gchar*)data);
+}
+
 /** Print a message after some seconds of delay. */
 void
 game_gui_print_message_with_delay(const gchar *format, ...)
@@ -440,7 +444,7 @@
     local_text = g_strdup_printf("___%s", text);
 
     g_timeout_add(const_int("int_game_gui_message_delay") * 1000,
-		  (GSourceFunc)game_gui_print_message, local_text);
+		  (GSourceFunc)print_test, local_text);
 }
 
 /** Function that gets called from time to time. */
