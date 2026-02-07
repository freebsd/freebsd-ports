--- main.c.orig	1998-01-22 14:34:05 UTC
+++ main.c
@@ -55,11 +55,11 @@
 #endif
 
 
+#include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include "xrobots.h"
 
-#define srandom srand
-#define random rand
-
 /*----------------------------------------------------------------------*/
 
 Widget top_shell, top_widget, playfield_widget, score_command, sonic_command;
@@ -153,13 +153,7 @@ static XtActionsRec actions[] = {
   {"do_nothing",(XtActionProc)do_nothing_action},
 };
 
-Pixel fg, bg;
-Boolean spiffy,			/* limited graphics 			*/
-	autoteleport,		/* teleport when sonic used, and no moves */
-	autoteleportalways,	/* teleport when no available moves 	*/
-	showjumps,		/* show no intermediate moves 		*/
-	diewaiting;		/* die if you use wait unsafely 	*/
-XtTranslations translations;
+AppData app_data;
 
 static XrmOptionDescRec options[] = {
 	{"-spiffy",	"spiffy",	XrmoptionSepArg, NULL },
@@ -172,29 +166,30 @@ static XrmOptionDescRec options[] = {
 
 static XtResource application_resources[] = {
   {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
-                (Cardinal)&fg, XtRString, (caddr_t) "Black"},
+                XtOffsetOf(AppData, fg), XtRString, (caddr_t) "Black"},
   {"background", "Background", XtRPixel, sizeof(Pixel),
-                (Cardinal)&bg, XtRString, (caddr_t) "White"},
+                XtOffsetOf(AppData, bg), XtRString, (caddr_t) "White"},
   {"spiffy", "Spiffy", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&spiffy, XtRString, (caddr_t) "True"},
+                XtOffsetOf(AppData, spiffy), XtRString, (caddr_t) "True"},
   {"autoteleport", "Autoteleport", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&autoteleport, XtRString, (caddr_t) "False"},
+                XtOffsetOf(AppData, autoteleport), XtRString, (caddr_t) "False"},
   {"autoteleportalways", "Autoteleportalways", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&autoteleportalways, XtRString, (caddr_t) "False"},
+                XtOffsetOf(AppData, autoteleportalways), XtRString, (caddr_t) "False"},
   {"showmovement", "Showmovement", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&showjumps, XtRString, (caddr_t) "True"},
+                XtOffsetOf(AppData, showjumps), XtRString, (caddr_t) "True"},
   {"diewaiting", "Diewaiting", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&diewaiting, XtRString, (caddr_t) "False"},
+                XtOffsetOf(AppData, diewaiting), XtRString, (caddr_t) "False"},
   {"translations","Translations", XtRTranslationTable, sizeof(XtTranslations),
-                (Cardinal)&translations, XtRString, (caddr_t)translations_str},
+                XtOffsetOf(AppData, translations), XtRString, (caddr_t)translations_str},
   {"scorefile","Scorefile", XtRString, sizeof(String),
-                (Cardinal)&score_filename, XtRString, (caddr_t)SCORE_FILE},
+                XtOffsetOf(AppData, score_filename), XtRString, (caddr_t)SCORE_FILE},
 };
 
 /*----------------------------------------------------------------------*/
 
+int
 main(argc, argv)
-  unsigned int argc;
+  int argc;
   char **argv;
 {
   Arg args[1];
@@ -212,7 +207,7 @@ main(argc, argv)
 
   XtAddActions(actions,XtNumber(actions));
 
-  XtGetApplicationResources(top_shell, 0, application_resources, 
+  XtGetApplicationResources(top_shell, &app_data, application_resources, 
 			XtNumber(application_resources), NULL, 0 );
 
   top_widget = XtCreateManagedWidget(
@@ -228,7 +223,7 @@ main(argc, argv)
                                     arglistplayfield,
                                     XtNumber(arglistplayfield));
 
-  XtAugmentTranslations(playfield_widget,translations);
+  XtAugmentTranslations(playfield_widget,app_data.translations);
 
   teleport_command = XtCreateManagedWidget(
                                     "teleport_button",
@@ -292,12 +287,12 @@ main(argc, argv)
 
   display   = XtDisplay(playfield_widget);
   playfield = XtWindow(playfield_widget);
-  gcv.foreground = fg;
-  gcv.background = bg;
+  gcv.foreground = app_data.fg;
+  gcv.background = app_data.bg;
   gcv.function = GXcopy;
   gc = XCreateGC(display, playfield, 
  		GCForeground | GCBackground | GCFunction, &gcv);
-  gcv.foreground = bg;
+  gcv.foreground = app_data.bg;
   cleargc = XCreateGC(display, playfield,
  		 GCForeground | GCBackground | GCFunction, &gcv);
 
