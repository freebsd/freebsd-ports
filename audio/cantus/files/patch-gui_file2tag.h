--- src/gui_file2tag.h.orig	2002-09-27 13:48:02.000000000 -0800
+++ src/gui_file2tag.h	2007-10-03 14:26:35.000000000 -0800
@@ -18,5 +18,5 @@
  */
 
 void file2tag_form_clear(void);
-void file2tag_form_fill(gchar *values[][]);
+void file2tag_form_fill(gchar ***values);
 
