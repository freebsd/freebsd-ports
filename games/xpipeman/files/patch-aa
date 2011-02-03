--- score.c.orig	1991-09-13 22:32:12.000000000 +0200
+++ score.c	2011-02-02 19:34:46.908945354 +0100
@@ -50,8 +50,9 @@
 #include <X11/Xaw/Label.h>
 #endif
 
-#include <X11/Xos.h>	/* brings in <sys/file.h> */
+#include <sys/file.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include "xpipeman.h"
 
 /*----------------------------------------------------------------------*/
@@ -64,7 +65,7 @@
 
 static SCORE scores[MAXSCORES];
 
-void 	show_scores(), 
+static void 	show_scores(), 
 	new_high_score(), 
 	load_scores(), 
 	write_out_scores();
@@ -198,7 +199,7 @@
 
 
 /*ARGSUSED*/
-static XtCallbackProc 
+static void
 popdown_callback(w, closure, call_data)
   Widget w;
   caddr_t closure;
