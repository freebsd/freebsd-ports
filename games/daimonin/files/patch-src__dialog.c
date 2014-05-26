--- ../../src/dialog.c.orig	2010-09-23 21:23:00.000000000 +0400
+++ ../../src/dialog.c	2014-05-26 19:19:13.000000000 +0400
@@ -580,7 +580,7 @@
 /******************************************************************
  draws all options for the actual page.
 ******************************************************************/
-inline void optwin_draw_options(int x, int y)
+void optwin_draw_options(int x, int y)
 {
 #define LEN_NAME  111
     int i = -1, pos = 0, max = 0;
