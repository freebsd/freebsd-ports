--- src/export/print.c.orig	2020-08-28 18:37:44 UTC
+++ src/export/print.c
@@ -30,7 +30,9 @@
 #include "export/exportlilypond.h"
 #include "core/utils.h"
 
-
+gint LilyPond_stderr;       //A file descriptor to pipe for LilyPond's stderr
+GError *lily_err;
+GPid previewerpid;
   
 #if GTK_MAJOR_VERSION==3
 typedef enum
