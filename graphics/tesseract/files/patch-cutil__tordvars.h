--- ./cutil/tordvars.h.orig	2007-05-17 01:33:53.000000000 +0400
+++ ./cutil/tordvars.h	2007-07-18 15:54:41.000000000 +0400
@@ -45,8 +45,8 @@
 extern int similarity_debug;                /* Level of debug output */
 extern int write_raw_output;                /* Text before context */
 extern int write_output;                    /* Text file output */
-//extern "C" { extern int display_ratings; }  /* Show the ratings */
-extern int display_ratings;                 /* Show the ratings */
+extern "C" { extern int display_ratings; }  /* Show the ratings */
+//extern int display_ratings;                 /* Show the ratings */
 extern int show_bold;                       /* Use bold text */
 extern int display_text;                    /* Show word text */
 extern int display_blocks;                  /* Show word as boxes */
