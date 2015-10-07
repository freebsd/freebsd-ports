--- score.c.orig	1991-09-13 20:32:12 UTC
+++ score.c
@@ -50,8 +50,9 @@
 #include <X11/Xaw/Label.h>
 #endif
 
-#include <X11/Xos.h>	/* brings in <sys/file.h> */
+#include <sys/file.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "xpipeman.h"
 
 /*----------------------------------------------------------------------*/
@@ -64,13 +65,12 @@ typedef struct {
 
 static SCORE scores[MAXSCORES];
 
-void 	show_scores(), 
+static void 	show_scores(), 
 	new_high_score(), 
 	load_scores(), 
 	write_out_scores();
 
 static FILE *scorefile = 0;
-char *score_filename;
 
 /*----------------------------------------------------------------------*/
 
@@ -100,8 +100,8 @@ load_scores()
 {
   int i = 0;
 
-  if( !(scorefile = fopen(score_filename,"r+")) ) {
-    scorefile = fopen(score_filename, "w");
+  if( !(scorefile = fopen(app_data.score_filename,"r+")) ) {
+    scorefile = fopen(app_data.score_filename, "w");
     return;
   }
 #ifndef SYSV
@@ -198,7 +198,7 @@ static Arg arglist_popdown[] = {
 
 
 /*ARGSUSED*/
-static XtCallbackProc 
+static void
 popdown_callback(w, closure, call_data)
   Widget w;
   caddr_t closure;
