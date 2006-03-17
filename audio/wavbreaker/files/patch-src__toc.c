--- src/toc.c.orig	Sun Sep 18 01:43:20 2005
+++ src/toc.c	Mon Feb 27 13:31:04 2006
@@ -33,6 +33,8 @@
 int toc_write_file(const char *toc_filename, const char *wav_filename, GList *breaks)
 {
     FILE *fp;
+    int i;
+    int len;
     TrackBreak *next_break = NULL;
     char *tocTime;
     char *tocDuration;
@@ -41,8 +43,8 @@
     if(!fp) return 1;
 
     fprintf(fp, "// Generated with wavbreaker\n\nCD_DA\n");
-    int i = 0;
-    int len = g_list_length(breaks);
+    i = 0;
+    len = g_list_length(breaks);
     while (i < len) {
         next_break = (TrackBreak *) g_list_nth_data(breaks, i);
         if (next_break != NULL) {
