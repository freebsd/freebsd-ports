--- FL/editengine.h.orig	Sat Aug 18 18:19:59 2001
+++ FL/editengine.h	Sat Aug 18 17:12:48 2001
@@ -113,6 +113,7 @@
   rclError SetTabs(short *tabs);
   rclError ChangeWidth(short newwidth)      { Width = newwidth; return Command(REFORMAT,(long)newwidth); };
   rclError LoadFrom(const char *buffer);
+  rclError LoadSQL(const char *query);
   rclError SaveTo(char *buffer);
   rclError LoadFrom(FILE *infile);
   rclError SaveTo(FILE *outfile);
