--- score.c.orig	1998-01-22 14:58:52 UTC
+++ score.c
@@ -56,6 +56,7 @@
 
 #include <X11/Xos.h>	/* brings in <sys/file.h> */
 #include <stdio.h>
+#include <stdlib.h>
 #include "xrobots.h"
 
 /*----------------------------------------------------------------------*/
@@ -67,14 +68,13 @@ typedef struct {
 
 static SCORE scores[MAXSCORES];
 
-void 	show_scores(),   
+static void 	show_scores(),   
 	write_out_scores();
 	
 static void new_high_score(),
 	    load_scores();
 
 static FILE *scorefile = 0;
-char *score_filename;
 
 /*----------------------------------------------------------------------*/
 
@@ -103,19 +103,20 @@ static void load_scores()
 {
   int i = 0;
 
-  if( !(scorefile = fopen(score_filename,"r+")) ) {
-    scorefile = fopen(score_filename, "w");
+  if( !(scorefile = fopen(app_data.score_filename,"r+")) ) {
+    scorefile = fopen(app_data.score_filename, "w");
     return;
   }
 #ifndef SYSV
   flock(scorefile->_file, LOCK_EX);
 #endif
-  while( fgets(scores[i].score,6,scorefile) 	/* get score */
-      && fgets(scores[i].name,26,scorefile) 	/* get name */
-      && fgetc(scorefile))			/* and newline */
-  {
-    i++;
-    if( i > MAXSCORES ) break;
+  for(i = 0; i < MAXSCORES; i++) {
+    if(!fgets(scores[i].score, 6, scorefile)) 	/* get score */
+      break;
+    if(!fgets(scores[i].name, 26, scorefile)) 	/* get name */
+      break;
+    if(!fgetc(scorefile))			/* and newline */
+      break;
   }
 }
 
@@ -194,7 +195,7 @@ static Arg arglist_popdown[] = {
 
 
 /*ARGSUSED*/
-static XtCallbackProc 
+static void
 popdown_callback(w, closure, call_data)
   Widget w;
   caddr_t closure;
@@ -253,7 +254,7 @@ void
 show_scores()
 {
   int i;
-  char tmp_str[31];
+  char tmp_str[64];
   Arg tmp_arg;
 
   for(i = 0;i<MAXSCORES;i++) {
