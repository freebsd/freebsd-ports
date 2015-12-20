--- src/export/print.c.orig	2015-10-26 04:58:33 UTC
+++ src/export/print.c
@@ -544,6 +544,9 @@ create_pdf (gboolean part_only, gboolean
 
 void create_pdf_for_lilypond (gchar *lilypond)
 {
+#ifndef USE_EVINCE
+  g_debug("This feature requires denemo to be built with evince");
+#else
          if (get_print_status()->printpid != GPID_NONE)
     {
       if (confirm (_("Already Typesetting"), _("Abandon this typeset?")))
@@ -567,6 +570,7 @@ void create_pdf_for_lilypond (gchar *lil
   get_print_status()->invalid = 0;
   run_lilypond_for_pdf (filename, lilyfile);  
   g_child_watch_add (get_print_status()->printpid, (GChildWatchFunc) printview_finished, (gpointer) (FALSE));
+#endif
 }
 /** 
  * Dialog function used to select measure range 
