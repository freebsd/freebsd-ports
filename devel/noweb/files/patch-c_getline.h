--- c/getline.h.orig	2006-06-12 21:16:23 UTC
+++ c/getline.h
@@ -1,6 +1,6 @@
-char *getline_expand (FILE *fp);
+char *get_line_expand (FILE *fp);
   /* grab a line in buffer, return new buffer or NULL for eof
      tabs in line are expanded according to tabsize */
-char *getline (FILE *fp);
+char *get_line (FILE *fp);
   /* grab a line in the buffer, return a new buffer or NULL for eof
      no expansion of tabs */
