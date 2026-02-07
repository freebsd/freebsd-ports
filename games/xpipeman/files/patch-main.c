--- main.c.orig	1991-09-13 20:32:10 UTC
+++ main.c
@@ -53,6 +53,9 @@
 #endif
 
 
+#include <stdlib.h>
+#include <stdio.h>
+#include <unistd.h>
 #include "xpipeman.h"
 
 /*----------------------------------------------------------------------*/
@@ -138,9 +141,7 @@ static XtActionsRec actions[] = {
   {"do_nothing",(XtActionProc)do_nothing_action},
 };
 
-Pixel fg, bg;
-
-XtTranslations translations;
+AppData app_data;
 
 static XrmOptionDescRec options[] = {
 	{"-scorefile","scorefile",XrmoptionSepArg, NULL },
@@ -148,19 +149,20 @@ static XrmOptionDescRec options[] = {
 
 static XtResource application_resources[] = {
   {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
-                (Cardinal)&fg, XtRString, (caddr_t) "Black"},
+                XtOffsetOf(AppData, fg), XtRString, (caddr_t) "Black"},
   {"background", "Background", XtRPixel, sizeof(Pixel),
-                (Cardinal)&bg, XtRString, (caddr_t) "White"},
+                XtOffsetOf(AppData, bg), XtRString, (caddr_t) "White"},
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
@@ -170,14 +172,14 @@ main(argc, argv)
 
   srandom(getpid());
   current_block = 0;
-  current_callback = NULL;
+  current_callback = 0;
 
   top_shell = XtInitialize(argv[0], "xpipeman", options, XtNumber(options), &argc, argv);
   XtSetValues(top_shell, arglisttop_shell, XtNumber(arglisttop_shell));
 
   XtAddActions(actions,XtNumber(actions));
 
-  XtGetApplicationResources(top_shell, 0, application_resources, 
+  XtGetApplicationResources(top_shell, &app_data, application_resources, 
 			XtNumber(application_resources), NULL, 0 );
 
   top_widget = XtCreateManagedWidget(
@@ -193,7 +195,7 @@ main(argc, argv)
                                     arglistplayfield,
                                     XtNumber(arglistplayfield));
 
-  XtAugmentTranslations(playfield_widget,translations);
+  XtAugmentTranslations(playfield_widget,app_data.translations);
 
   quit_command = XtCreateManagedWidget(
                                     "quit_button",
@@ -263,12 +265,12 @@ main(argc, argv)
 
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
 
@@ -318,7 +320,7 @@ void
 update_remain(score)
   int score;
 {
-  char text[13];
+  char text[16];
   (void)sprintf(text,"Remaining: %4d",score);
   XtSetArg(arglistremain_command[0],XtNlabel,text);
   XtSetValues(remain_command,arglistremain_command,1);
