--- src/export/print.h.orig	2020-08-28 18:38:07 UTC
+++ src/export/print.h
@@ -108,9 +108,9 @@ typedef struct WysiwygInfo
   GtkWidget *dialog;            //an info dialog to tell the user what to do next...
 } WysiwygInfo;
 
-gint LilyPond_stderr;       //A file descriptor to pipe for LilyPond's stderr
-GError *lily_err;
-GPid previewerpid;
+extern gint LilyPond_stderr;       //A file descriptor to pipe for LilyPond's stderr
+extern GError *lily_err;
+extern GPid previewerpid;
 
 WysiwygInfo* get_wysiwyg_info();
 void initialize_print_status (void);
