--- autozen.c.orig	2001-09-16 02:09:04 UTC
+++ autozen.c
@@ -27,7 +27,7 @@
  
 /* "The nice thing about standards..." */
 #if defined (__FreeBSD__)
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #else
 #if defined (__NetBSD__) || defined (__OpenBSD__)
 #include <soundcard.h>          /* OSS emulation */
@@ -113,7 +113,7 @@ char bQuit=0;
 //
 /////////////////////////////////
 
-#define SAMPLE_RATE 8000
+#define SAMPLE_RATE 11025
 
 #define MAX_HARMONICS 10
 #define DEFAULT_HARMONICS 3
@@ -253,7 +253,7 @@ void Play (GtkWidget *widget, gpointer d
 }
 
 
-int CheckSequencer()
+void CheckSequencer()
 {
 char *token;
 int tmp;
@@ -672,7 +672,7 @@ void *SoundThread(void *v)
 
 	}	// end while		
 
-return;
+return(NULL);
 }
 
 gint volTimeOut(gpointer data) {
@@ -729,6 +729,11 @@ GtkWidget *create_HelpWindow (const char
 	GtkWidget *help_text;
 	GtkWidget *HelpQuit;
 
+#if GTK_MAJOR_VERSION >= 2
+	GtkTextIter help_text_iter;
+	GtkTextBuffer *help_text_buf;
+#endif
+
 	HelpWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
 	gtk_object_set_data (GTK_OBJECT (HelpWindow), "HelpWindow", HelpWindow);
 	gtk_window_set_title (GTK_WINDOW (HelpWindow), "AutoZen Help");
@@ -740,9 +745,16 @@ GtkWidget *create_HelpWindow (const char
 	gtk_widget_show (vbox1);
 	gtk_container_add (GTK_CONTAINER (HelpWindow), vbox1);
 
+#if GTK_MAJOR_VERSION >= 2
+	help_text = gtk_text_view_new ();
+	help_text_buf = gtk_text_view_get_buffer (GTK_TEXT_VIEW (help_text));
+	gtk_text_buffer_get_iter_at_offset (help_text_buf, &help_text_iter, 0);
+	gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW (help_text), GTK_WRAP_WORD);
+#else
 	help_text = gtk_text_new (NULL, NULL);
 	gtk_text_set_word_wrap( GTK_TEXT( help_text ), TRUE);
 	gtk_text_set_line_wrap( GTK_TEXT( help_text ), TRUE);
+#endif
 
 
 	gtk_object_set_data (GTK_OBJECT (HelpWindow), "help_text", help_text);
@@ -751,7 +763,11 @@ GtkWidget *create_HelpWindow (const char
 //	gtk_widget_set_sensitive (help_text, FALSE);
 	GTK_WIDGET_UNSET_FLAGS (help_text, GTK_CAN_FOCUS);
 	gtk_widget_realize (help_text);
+#if GTK_MAJOR_VERSION >= 2
+	gtk_text_buffer_insert (help_text_buf, &help_text_iter, text, strlen(text));
+#else
 	gtk_text_insert (GTK_TEXT (help_text), NULL, NULL, NULL, text, strlen(text));
+#endif
 
 	HelpQuit = gtk_button_new_with_label ("Close");
 	gtk_object_set_data (GTK_OBJECT (HelpWindow), "HelpQuit", HelpQuit);
